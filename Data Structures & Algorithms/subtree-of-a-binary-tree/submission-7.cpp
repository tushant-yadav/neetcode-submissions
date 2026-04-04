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
    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(root==nullptr && subRoot==nullptr) return 1;
        if(root==nullptr || subRoot==nullptr) return 0;
        if(root->val!=subRoot->val) return 0;
        return isSame(root->left, subRoot->left)&&isSame(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr) return 0;
        
        if(isSame(root,subRoot)) return 1;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }
};
