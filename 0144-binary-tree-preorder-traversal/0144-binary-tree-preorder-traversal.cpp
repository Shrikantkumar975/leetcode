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
    void helper(vector<int> &v,TreeNode* root){
        if(root == nullptr) return;

        v.push_back(root->val);
        helper(v,root->left);
        helper(v,root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>  v;
        helper(v,root);
        return v;
    }
};