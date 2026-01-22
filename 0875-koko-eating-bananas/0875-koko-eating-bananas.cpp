class Solution {
public:
    long long check(int mid,vector<int> &piles){
        long long ans = 0;
        for(int i=0;i<piles.size();i++){
            ans+=ceil(piles[i]*1.00/mid);
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1e9;
        int ans=-1;

        while(low<=high){
            int mid = (high + low)/2;
            long long curr = check(mid,piles);
            if(curr<=h){
                ans=mid;
                high = mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};