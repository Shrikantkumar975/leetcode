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
    unordered_map<TreeNode*,int> mpp;
    int maxD=0;

    void depth(TreeNode* root,int d){
        if(!root) return;

        mpp[root]=d;
        maxD = max(maxD,d);
        depth(root->left,d+1);
        depth(root->right,d+1);
    }

    TreeNode* LCA(TreeNode* root){
        if(!root) return nullptr;
        if(mpp[root]==maxD) return root;

        TreeNode* left = LCA(root->left);
        TreeNode* right = LCA(root->right);

        if(left && right) return root;
        if(left) return left;
        if(right) return right;
        return nullptr;
    }


    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth(root,0);

        return LCA(root);
    }
};