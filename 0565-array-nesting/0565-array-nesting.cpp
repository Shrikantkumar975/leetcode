class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxi=0;
        vector<int> v(nums.size(),0);

        for(int i=0;i<nums.size();i++){
            int len=0;
            if(nums[i]!=0){
                int j=nums[i];
                v[i]=1;
                while(j!=nums[i] || len==0){
                    if(v[j]==1) break;
                    len++;
                    v[j]=1;
                    j=nums[j];
                }
                maxi = max(maxi,len);
            }
        }

        return maxi+1;
    }
};