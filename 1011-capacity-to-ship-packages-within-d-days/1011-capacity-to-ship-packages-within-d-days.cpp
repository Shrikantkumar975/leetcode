class Solution {
public:

    int checkMid(vector<int> arr,int mid){
        int sum=0;
        int countDay = 1;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }else{
                sum = arr[i];
                countDay++;
            }
        }
        return countDay;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int max = weights[0];
        int sum = 0;
        int ans =-1;
        for (int ele : weights) {
            if (ele > max)
                max = ele;
            sum += ele;
        }
        int lCap = max, hCap = sum;

        while (lCap <= hCap) {
           int  mid = (lCap + hCap) / 2;

            int a = checkMid(weights, mid);

            if (a <= days) {
                ans = mid;
                hCap = mid - 1;
            } else {
                lCap = mid + 1;
            }
        }
        return ans;
    }
};