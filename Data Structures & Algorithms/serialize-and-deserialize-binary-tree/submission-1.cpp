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
          1
    2           3
            4       5
1 2 3 n n 4 5 n n n n 

1 

 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
        
    }

    TreeNode* decode(stringstream& ss){
        string val;
        getline(ss,val,',');

        if(val=="N") return nullptr;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = decode(ss);
        node->right = decode(ss);

        return node;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return decode(ss);
        
    }
};
