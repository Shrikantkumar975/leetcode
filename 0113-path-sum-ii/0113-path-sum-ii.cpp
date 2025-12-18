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
    void preorder(TreeNode* root,int &targetSum,int sum,vector<vector<int>>&v,vector<int>s){
        if(!root) return;
        sum+=root->val;
        s.push_back(root->val);
        if(!root->left && !root->right) {
            if(sum == targetSum) v.push_back(s);
        }
        preorder(root->left,targetSum,sum,v,s);
        preorder(root->right,targetSum,sum,v,s);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> v;
        vector<int> s;

        preorder(root,targetSum,0,v,s);
        return v;
    }
};