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
    string dfs(TreeNode* root){
        if(!root) return "";
        string s1="";

        s1+=to_string(root->val);

        if(!root->left && !root->right) return s1;

        s1+="(";
        string s2= dfs(root->left);
        s1+=s2 + ")";

        // s1+="(";
        string s3= dfs(root->right);
        // s1+=s3 + ")";

        // if(!root->left) return s1 += "()";

        if(!root->right) return s1;

        return s1+"("+s3+")";
    }

    string tree2str(TreeNode* root) {
        if(!root) return "";

        string s="";
        // s+="(";
        string s1 = dfs(root);
        s+=s1;

        return s;
    }
};