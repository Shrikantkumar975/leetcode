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
    void preorder(TreeNode* root,int &targetSum,long long sum,int &ans){
        if(!root) return;

        sum+=root->val;
        if(sum==targetSum){
            ans++;
        }

        preorder(root->left,targetSum,sum,ans);
        preorder(root->right,targetSum,sum,ans);
    }

    void goToEvery(TreeNode* root,int &targetSum,int &ans){
        if(!root) return;

        preorder(root,targetSum,0,ans);

        goToEvery(root->left,targetSum,ans);
        goToEvery(root->right,targetSum,ans);
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;

        goToEvery(root,targetSum,ans);

        return ans;
    }
};