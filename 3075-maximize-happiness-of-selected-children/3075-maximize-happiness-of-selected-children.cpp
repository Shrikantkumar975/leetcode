class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans =0;
        sort(happiness.begin(),happiness.end(),greater<int>());
        int n=happiness.size();
        int turn = 0;
        for(int i=0;i<n;i++){
            if(k==0) break;
            if(happiness[i]-turn<=0) break;
            ans+=happiness[i]-turn;
            turn++;
            k--;
        }

        return ans;
    }
};