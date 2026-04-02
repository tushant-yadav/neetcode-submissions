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
    bool issametree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot == NULL)
            return 1;
        if(root == NULL || subRoot==NULL)
            return 0;
        if(root->val!=subRoot->val)
            return 0;

        return issametree(root->left, subRoot->left) && issametree(root->right, subRoot->right);     

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return 0;
        if(issametree(root,subRoot)) return 1;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
