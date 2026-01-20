class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        const int n=nums.size();
        vector<int> ans;

        for(int i=0; i<n; i++) {
            int a=-1;
            for(int x=0;x<nums[i];x++){
                if((x | (x+1)) == nums[i]){
                    a=x;
                    break;
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};