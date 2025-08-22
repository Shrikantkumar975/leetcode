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
       queue<TreeNode*> q;
       if(root==nullptr) return 0;
       q.push(root);
       int count =0;

       while(!q.empty()){
            int size = q.size();

            while(size--){
            TreeNode* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            }
            count++;
       }

       return count;
    }
};