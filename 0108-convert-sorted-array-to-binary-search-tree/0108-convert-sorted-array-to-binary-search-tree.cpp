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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right){
        if(left > right) return NULL;
        int mid = left + (right - left)/2;
        TreeNode* res = new TreeNode(nums[mid]);
        res->left = sortedArrayToBST(nums, left, mid - 1);
        res->right = sortedArrayToBST(nums, mid + 1, right);
        return res;
    }
};