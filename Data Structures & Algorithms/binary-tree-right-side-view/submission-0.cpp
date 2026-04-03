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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if(root==NULL) return {};
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> v1;
            while(n--){
                TreeNode* top = q.front();
                q.pop();
                v1.push_back(top->val);
                if(top->left!=NULL) q.push(top->left);
                if(top->right!=NULL) q.push(top->right);
            }
            v.push_back(v1);
        }
        return v;   
    } 
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> v = levelOrder(root);

        vector<int> ans;
        int n = v.size();
        for(int i=0;i<n;i++){
            ans.push_back(v[i][v[i].size()-1]);
        }
        return ans;
        
    }
};
