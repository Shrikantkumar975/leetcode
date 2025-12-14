class Solution {
public:
    const long long  MOD=1e9+7;

    int numberOfWays(string corridor) {
        vector<int> v;

        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S') v.push_back(i);
        }


        if(v.size()<2 || v.size()%2!=0) return 0;

        long long ans = 1;

        for (int i = 2; i < v.size(); i += 2) {
            ans = (ans * (v[i] - v[i - 1])) % MOD;
        }
        
        return ans;

    }
};