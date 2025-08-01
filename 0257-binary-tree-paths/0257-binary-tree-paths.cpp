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

    void preorder(TreeNode* root,string s,vector<string>&v){
        if(!root) return;
        if(!s.empty()) s +="->"+to_string(root->val);
        else s+=to_string(root->val);
        if(!root->left && !root->right) v.push_back(s);

        preorder(root->left,s,v);
        preorder(root->right,s,v); 
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s= "";
        vector<string> v;

        preorder(root,s,v);

        return v;
    }
};