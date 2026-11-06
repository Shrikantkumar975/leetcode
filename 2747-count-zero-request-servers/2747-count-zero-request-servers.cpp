
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](const auto& a, const auto& b) {
                 return a[1] < b[1];
             });

        vector<pair<int,int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        unordered_map<int, int> freq;
        vector<int> ans(queries.size());

        int i = 0, j = 0;

        for (auto [time, idx] : q) {

            int l = time - x;
            int r = time;

            // Add logs inside the right boundary
            while (j < logs.size() && logs[j][1] <= r) {
                freq[logs[j][0]]++;
                j++;
            }

            // Remove logs outside the left boundary
            while (i < j && logs[i][1] < l) {
                freq[logs[i][0]]--;

                if (freq[logs[i][0]] == 0) {
                    freq.erase(logs[i][0]);
                }

                i++;
            }

            ans[idx] = n - freq.size();
        }

        return ans;
    }
};
