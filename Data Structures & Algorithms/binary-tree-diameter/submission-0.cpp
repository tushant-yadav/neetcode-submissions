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
    pair<int,int> solve(TreeNode* root){
        if(root == nullptr) return {0,0};
        int height = 0, dia = 0;
        pair<int,int> l = solve(root->left);
        pair<int,int> r = solve(root->right);
        height = max(l.first,r.first)+1;
        dia = max(l.first+r.first+1, max(l.second, r.second));
        return {height, dia};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> p = solve(root);
        return max(p.first,p.second)-1;
    }
};
