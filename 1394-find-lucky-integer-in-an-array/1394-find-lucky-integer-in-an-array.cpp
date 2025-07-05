class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }

        int ans=-1;

        for(auto a: m){
            if(a.first == a.second && a.first > ans){
                ans = a.first;
            }
        }

        return ans;

    }
};