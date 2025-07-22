class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        map<int,int> m;

        for(int i=0;i<nums.size()-1;i++){
                int sum = nums[i] + nums[i+1];
                if(m.count(sum)) return true;

                m[sum]++;
        }

        return false;
    }
};