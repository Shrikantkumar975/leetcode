class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        vector<vector<string>> ans;

        for(string s: strs){
            string ns=s;
            sort(ns.begin(),ns.end());
            mpp[ns].push_back(s);
        }

        for(auto m: mpp){
            ans.push_back(m.second);
        }
        return ans;
    }
};