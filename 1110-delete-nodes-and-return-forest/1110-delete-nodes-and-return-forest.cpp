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
    unordered_set<int> st;
    TreeNode* del(TreeNode* root,vector<TreeNode*> &v){
        if(!root) return nullptr;

        root->left = del(root->left,v);
        root->right = del(root->right,v);

        if(st.find(root->val)!=st.end()){
            if(root->left) v.push_back(root->left);
            if(root->right) v.push_back(root->right);
            return nullptr;
        }

        return root;

    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int &a: to_delete){
            st.insert(a);
        }

        vector<TreeNode*> v;

        root = del(root,v);
        if(!root) return v;

        if(st.find(root->val)!=st.end()){
            if(root->left) v.push_back(root->left);
            if(root->right) v.push_back(root->right);
        }
        else{
            v.push_back(root);
        }

        return v;
    }
};