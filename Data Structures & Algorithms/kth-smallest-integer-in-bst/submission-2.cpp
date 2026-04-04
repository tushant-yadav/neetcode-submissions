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
    // int helper(TreeNode* root, int &k){
    //     if(root==nullptr) return -1;
    //     int ans = helper(root->left, k);
    //     if(ans!=-1) return ans;
    //     k--;
    //     if(k==0){
    //         return root->val;
    //     }
    //     return  helper(root->right,k);
    // }
    int kthSmallest(TreeNode* root, int &k) {
        if(root==nullptr) return -1;
        int ans = kthSmallest(root->left, k);
        if(ans!=-1) return ans;
        k--;
        if(k==0){
            return root->val;
        }
        return  kthSmallest(root->right,k);
    }
};
