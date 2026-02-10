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
    void dfs(TreeNode* root,vector<int> &v,int &level,int curr){
        if(curr==level){
            v.push_back(root->val);
            level++;
        }

        if(root->right) dfs(root->right,v,level,curr+1);
        if(root->left) dfs(root->left,v,level,curr+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> v;
        int level =1;

        dfs(root,v,level,1);

        return v;
    }
};