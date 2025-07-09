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
    void preorder(TreeNode* root,int count,int& max){
        if(!root) return;
        count++;
        if(!root->left && !root->right){
            if(count>max) max = count;
        }
        preorder(root->left,count,max);
        preorder(root->right,count,max);
    }
    int maxDepth(TreeNode* root) {
        int max =0;
        int count =0;
        preorder(root,count,max);
        return max;
    }
};