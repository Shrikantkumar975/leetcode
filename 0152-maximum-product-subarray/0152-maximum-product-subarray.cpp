class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> pp(nums.size(),0);
        vector<int> sp(nums.size(),0);
        pp[0]=nums[0];
        sp[nums.size()-1]=nums[nums.size()-1];

        // int prod=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==0) continue;
            pp[i]= nums[i]*pp[i-1];
        }

        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]==0) continue;
            sp[i]= nums[i]*sp[i+1];
        }

        int maxi=INT_MIN;

        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,max(pp[i],sp[i]));
        }

        return maxi;
    }
};