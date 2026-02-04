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
        int low = 0;
        int high = *max_element(citations.begin(),citations.end());

        int ans=0;
        while(low<=high){
            int mid = low + (high - low)/2;

            if(check(mid,citations)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        return ans;
    }
};