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
    int ans;

    pair<int,int> dfs(TreeNode* root){
        if(root==nullptr) return {0,0};

        pair<int,int> left = dfs(root->left);
        pair<int,int> right = dfs(root->right);

        int total = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        if(total/count == root->val) ans++;

        return {total,count};
    }

    int averageOfSubtree(TreeNode* root) {
        ans =0;

        pair<int,int> p = dfs(root);

        return ans;
    }
};