class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n= nums.size();
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

            int j=i+1;
            int k=n-1;
            while(j<k){
                if(nums[j]+nums[k] > -1*nums[i]) k--;
                else if(nums[j]+nums[k] < -1*nums[i]) j++;
                else{
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
            }
        }
        return res;
    }
};