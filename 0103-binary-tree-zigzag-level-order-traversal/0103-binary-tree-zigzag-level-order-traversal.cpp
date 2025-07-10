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
        if(!root) return v;
        int i=0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> s;

            while(size--){
                TreeNode* curr = q.front();
                q.pop();

                s.push_back(curr->val);

                if(i%2==0){
                    if(curr->right) q.push(curr->right);
                    if(curr->left) q.push(curr->left);
                }else{
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
            }
            i++;
            v.push_back(s);
        }
        return v;
    }
};