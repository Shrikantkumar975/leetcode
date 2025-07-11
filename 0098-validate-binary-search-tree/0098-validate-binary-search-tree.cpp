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
    void helper(TreeNode* root,long a,long b,bool& m){
        if(!m ||!root) return;

        if(root->val <= a || root->val >= b){
            m=false;
            return;
        }

        helper(root->left,a,root->val,m);
        helper(root->right,root->val,b,m);

    }
    bool isValidBST(TreeNode* root) {
        bool m = true;

        helper(root,LONG_MIN,LONG_MAX,m);

        return m;
    }
};