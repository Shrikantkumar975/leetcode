class Solution {
public:

    int checkMid(vector<int> arr,int mid){
        long count=0;

        for(long ele: arr){
            count+=(ele+mid-1LL)/mid;
        }

        return count;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long low =1;
        long high =1e9;
        long ans = -1;

        while(low<=high){
            long mid = low + (high-low)/2;
            long a = checkMid(piles,mid);

            if(a<=h){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};