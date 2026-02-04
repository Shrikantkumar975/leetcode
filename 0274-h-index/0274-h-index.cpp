class Solution {
public:

    bool check(int n,vector<int> citations){
        int num = n;
        int count=0;
        for(int i=0;i<citations.size();i++){
            if(citations[i]>=num) count++;
        }

        return count>=num;
    }

    int hIndex(vector<int>& citations) {
        int ans = 1;
        int maxi = *max_element(citations.begin(),citations.end());

        for(int i=1;i<=maxi;i++){
            if(check(i,citations)){
                ans =max(ans,i);
            }
        }

        return ans;
    }
};