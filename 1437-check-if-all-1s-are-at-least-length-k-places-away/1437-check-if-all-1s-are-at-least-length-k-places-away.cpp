class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        // stack<int> st;
        int prev=-1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1 && prev!=-1){
                if(i-prev<=k) return false;
                else prev=i;
            }else if(nums[i]==1){
                prev=i;
            }
        }

        return true;
    }
};