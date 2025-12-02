class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int MOD = 1e9 + 7;

        unordered_map<int, set<int>> mpp;

        for (int i = 0; i < points.size(); i++) {
            mpp[points[i][1]].insert(points[i][0]);
        }

        long long sum = 0;
        int ans = 0;

        vector<pair<int,int>> mpp2;

        for (auto& m : mpp) {
            long long a = m.second.size();
            int select = (a*(a-1))/2;
            mpp2.push_back({m.first,select});
        }

        sort(mpp2.begin(),mpp2.end());

        for (auto& m : mpp2) {
            ans = (ans + 1LL * sum * m.second) % MOD;
            sum += m.second;
        }

        return ans;
    }
};