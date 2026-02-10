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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> mpp;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* u = q.front();
            q.pop();

            if (u->left) {
                mpp[u->val].push_back(u->left->val);
                mpp[u->left->val].push_back(u->val);
                q.push(u->left);
            }
            if (u->right) {
                mpp[u->val].push_back(u->right->val);
                mpp[u->right->val].push_back(u->val);
                q.push(u->right);
            }
        }

        queue<int> q2;
        q2.push(start);

        set<int> st;
        st.insert(start);
        int step = -1;

        while (!q2.empty()) {
            int size = q2.size();
            step++;

            while (size--) {
                int u = q2.front();
                q2.pop();

                for (int v : mpp[u]) {
                    if (st.find(v) == st.end()) {
                        q2.push(v);
                        st.insert(v);
                    }
                }
            }
        }
        return step;
    }
};