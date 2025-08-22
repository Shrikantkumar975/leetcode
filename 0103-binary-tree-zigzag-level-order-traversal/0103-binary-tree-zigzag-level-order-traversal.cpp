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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root == nullptr) return v;

        queue<TreeNode*> q;
        q.push(root);
        int a=1;
        while(!q.empty()){
            int size = q.size();
            vector<int> v1;

            while(size--){
                TreeNode* node = q.front();
                q.pop();
                v1.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(a%2==0) reverse(v1.begin(),v1.end());
            v.push_back(v1);
            a++;
        }
        return v;
    }
};