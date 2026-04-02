/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    bool helper(TreeNode* root, int minimum, int maximum){
        if(root==NULL) return 1;
        if(root->val<=minimum || root->val>=maximum){
            return 0;
        }
        return helper(root->left, minimum, root->val) && helper(root->right, root->val, maximum);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root,-1000,1000);
    }
};
