class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for(int i=0;i<nums1.size();i++){
            int a = i;
            int low = i;
            int high = nums2.size()-1;

            while(low<=high){
                int mid = (low+high)/2;
                if(nums2[mid]>=nums1[i]){
                    a=mid;
                    low = mid+1;
                }
                else high = mid-1;
            }

            ans = max(ans,a-i);
        }

        return ans;
    }
};