class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mpp;

        for(int a: nums){
            mpp[a]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto m: mpp){
            pq.push({m.second,m.first});
        }

        while(k){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};