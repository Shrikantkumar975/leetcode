class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;

        int i=0;
        int j=0;
        int K=0;
        int maxK=0;

        while(j<nums.size()){
            mpp[nums[j]]++;
            
            while(i<j && mpp[nums[j]]>k){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                i++;
            }

            K=j-i+1;
            maxK = max(maxK,K);
            j++;
        }

        return maxK;
    }
};