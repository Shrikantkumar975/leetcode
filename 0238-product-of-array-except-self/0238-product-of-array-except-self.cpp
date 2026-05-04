class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int zeroCount=0;
        int zeroInd=-1;
        int prd=1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeroCount++;
                zeroInd=i;
            }else{
                prd*=nums[i];
            }
        }

        if(zeroCount>=2){
            for(int i=0;i<n;i++){
                nums[i]=0;
            }
        }else if(zeroCount==1){
            for(int i=0;i<n;i++){
                if(i==zeroInd) nums[i]=prd;
                else nums[i]=0;
            }
        }else{
            for(int i=0;i<n;i++){
                // if(nums[i]!=0)
                nums[i]=prd/nums[i];
            }
        }

        return nums;
    }
};