class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int maxi=1;
        int i=0;
        int j=0;

        while(j<nums.size()){
            if(nums[j]/k<=nums[i]){
                maxi =max(maxi,j-i+1);
                j++;
            }
            else(i++);
        }

        return nums.size()-maxi;
    }
};