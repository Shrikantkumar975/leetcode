class Solution {
public:
    bool fun(int m, int k, int mid , vector<int> &bloomDay){
        int noB= 0,count=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                count++;
                if(count==k){
                    noB+=count/k;
                    count=0;
                }
            }
            else count=0;
        }
        if(noB >= m) return 1;
        return 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mx = bloomDay[0];
        int mn = bloomDay[0];

        for(int a: bloomDay){
            if(a>mx) mx=a;
            if(a<mn) mn=a;
        }

        int low = mn,high = mx;
        int ans =-1;
        while(low<=high){
            int mid = (low+high)/2;

            if(fun(m,k,mid,bloomDay)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
   }
};