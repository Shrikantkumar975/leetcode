class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j] == target){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {-1,-1};

        unordered_map<int,int> mpp;

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=i;
        }

        for(int i=0;i<nums.size();i++){
            if(mpp.find(target-nums[i])!=mpp.end() && i!=mpp[target-nums[i]]) return {i,mpp[target-nums[i]]};
        }

        return {-1,-1};
    }
};