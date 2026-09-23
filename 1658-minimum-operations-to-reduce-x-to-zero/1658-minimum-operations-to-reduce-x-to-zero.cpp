class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i=0;
        int j=0;

        int total= accumulate(nums.begin(),nums.end(),0);
        int req = total-x;
        int curr=0;
        int maxi =-1;

        while(j<nums.size()){
            curr+=nums[j];

            while(i<=j && curr>req){
                curr -= nums[i];
                i++;
            }

            if(curr == req){
                maxi= max(maxi,j-i+1);
            }

            j++;
        }

        return maxi==-1?-1:nums.size()-maxi;
    }
};