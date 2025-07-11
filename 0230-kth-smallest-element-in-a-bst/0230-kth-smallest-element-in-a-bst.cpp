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
    int inorderFind(TreeNode* root,int k,int &i){
        if(!root) return -1;
        
        int left=inorderFind(root->left,k,i);
        if(left!=-1) return left;
        
        if(i==k) return root->val;
        i++;
        
        return inorderFind(root->right,k,i);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i=1;
        return inorderFind(root,k,i);
    }
};