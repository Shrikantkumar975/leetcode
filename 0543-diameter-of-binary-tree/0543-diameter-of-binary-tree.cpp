class Solution {
public:
    int calc(TreeNode* root, int& diameter) {
        if (!root) return 0;

        int left = calc(root->left, diameter);
        int right = calc(root->right, diameter);

        diameter = max(diameter, left + right); // update diameter

        return 1 + max(left, right); // return height
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        calc(root, diameter); // just call it to update diameter
        return diameter;
    }
};
