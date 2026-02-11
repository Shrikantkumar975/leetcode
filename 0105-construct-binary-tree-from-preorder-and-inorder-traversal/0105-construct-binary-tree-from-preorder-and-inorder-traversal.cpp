/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int idx = 0;
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int start,
                        int end) {
        if (start > end)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[idx++]);

        int i = 0;
        while (inorder[i] != root->val)
            i++;

        root->left = construct(preorder, inorder, start, i - 1);
        root->right = construct(preorder, inorder, i + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root =
            construct(preorder, inorder, 0, preorder.size() - 1);

        return root;
    }
};