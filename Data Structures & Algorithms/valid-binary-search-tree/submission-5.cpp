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
        if(root==nullptr) return 1;

        // cout<<root->val<<"::"<<minimum<<"::"<<maximum<<endl;
        if(root->val>=maximum || root->val<=minimum) return 0;

        return helper(root->left,minimum,root->val) && helper(root->right, root->val, maximum);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX);        
    }
};
