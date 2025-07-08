class Solution {
public:
    int check(vector<int>&arr, int mid){
        int count = 0;

        for(int i=0;i<arr.size();i++){
            if(arr[i]%mid==0) count+=arr[i]/mid;
            else count+=arr[i]/mid+1;
        }

        return count;
    }
    int minimizedMaximum(int n, vector<int>& arr) {
        int low =1;
        int high = *max_element(arr.begin(),arr.end());
    int x = -1;
        while(low<=high){
            int mid = (low+high)/2;
            int a = check(arr,mid);

            if(a<=n){
                x = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return x;
    }
};