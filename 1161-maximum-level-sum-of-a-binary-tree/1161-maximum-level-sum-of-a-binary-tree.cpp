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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxi = INT_MIN;
        int maxL = 0;
        int count =0;
        while(!q.empty()){
            count++;
            int size = q.size();
            int sum=0;
            while(size--){
            TreeNode* node = q.front();
            q.pop();
            sum+=node->val;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            }

            if(sum > maxi){
                maxi = sum;
                maxL = count;
            }
        }

        return maxL;
    }
};