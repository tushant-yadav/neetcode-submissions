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
    unordered_map<int, int> um;
    int n;
public:

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int s, int e, int &idx){
        if(s>e || idx>=n) return nullptr;

        int ele = preorder[idx];
        int pos = um[ele];
        idx++;
        //cout<<ele<<":"<<pos<<"{}"<<s<<"::"<<e<<endl;
        TreeNode* node = new TreeNode(ele);

        node->left = solve(preorder, inorder, s, pos-1,idx);
        node->right = solve(preorder, inorder, pos+1, e, idx);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = preorder.size();
        for(int i=0;i<n;i++){
            um[inorder[i]] = i;
        }
        int idx = 0;

        return solve(preorder,inorder,0,n-1,idx);
        
    }
};
