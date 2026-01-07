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
    long long maxi = 0ll;
    int INF = 1e9+7;
    
    void DFS(TreeNode* root,int &total){
        if(!root) return;
        int b = total-root->val;
        long long product =(long long)(root->val) * b;
        maxi = max(maxi,product);

        DFS(root->left,total);
        DFS(root->right,total);
    }

    long long goDeep(TreeNode* root){
        if(!root) return 0;
        // long long 
        root->val += goDeep(root->left) + goDeep(root->right); 
        return root->val;
    }

    int maxProduct(TreeNode* root) {
        
        long long total = goDeep(root);;
        DFS(root,root->val);
        return maxi%INF;
    }
};