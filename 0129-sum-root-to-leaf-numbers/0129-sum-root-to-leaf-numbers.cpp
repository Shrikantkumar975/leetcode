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
    void preorder(TreeNode* root,int curr,int &sum){
        if(!root) return ;

        curr=curr*10+root->val;
        if(!root->left && !root->right){
            sum += curr;
        }
        preorder(root->left,curr,sum);
        preorder(root->right,curr,sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum=0;
        int curr=0;

        preorder(root,curr,sum);

        return sum;
    }
};