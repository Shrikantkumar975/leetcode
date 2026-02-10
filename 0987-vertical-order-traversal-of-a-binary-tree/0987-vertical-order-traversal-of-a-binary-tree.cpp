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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        map < int, vector<pair<int, int>>> mp;

        queue<pair<TreeNode*, int>> q;

        int step = -1;
        q.push({root, 0});

        while (!q.empty()) {

            int size = q.size();
            step++;
            while (size--) {
                auto [a, b] = q.front();
                q.pop();
                mp[b].push_back({step, a->val});
                if (a->left != NULL)
                    q.push({a->left, b - 1});
                if (a->right != NULL)
                    q.push({a->right, b + 1});
            }
        }
        for (auto x : mp) {
            if (x.first == 0) {
                sort(x.second.begin(), x.second.end());
            } else {
                sort(x.second.begin(), x.second.end());
            }

            vector<int> v;
            for(auto [a,b]: x.second){
                v.push_back(b);
            }
            ans.push_back(v);
        }
        return ans;
    }
};