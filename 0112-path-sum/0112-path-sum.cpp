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
    void preorder(TreeNode* root,int &targetSum,int sum,bool &a){
        if(!root) return;
        sum+=root->val;
        if(!root->left && !root->right) {
            if(sum == targetSum) a =true;
            return;
        }
        preorder(root->left,targetSum,sum,a);
        preorder(root->right,targetSum,sum,a);
    }
    bool hasPathSum(TreeNode* root, int targetSum){
        bool a = false;
        preorder(root,targetSum,0,a);

        return a;
    }
};