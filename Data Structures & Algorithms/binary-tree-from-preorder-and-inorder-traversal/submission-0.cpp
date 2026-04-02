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
    unordered_map<int,int> mp;
    TreeNode* solve(vector<int> in,vector<int>& pre, int n, int s, int e, int &idx){
        if(s>e || idx>n) return NULL;
        int ele = pre[idx++];
        int pos = mp[ele];
        
        TreeNode* root = new TreeNode(ele);
        
        root->left = solve(in,pre, n, s, pos-1, idx);
        root->right = solve(in, pre, n, pos+1, e, idx);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in)
    {
        int n = pre.size();
        for(int i=0;i<n;i++){
            mp[in[i]] = i;
        }
        int idx=0;
        return solve(in, pre, n, 0, n-1, idx);
        
        // Code here
    }
};
