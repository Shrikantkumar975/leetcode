class Solution {
public:
    int minOperations(vector<int>& nums) {
        int OneCount = count(nums.begin(),nums.end(),1);
        int res=0;
        if(OneCount!=0){
            return nums.size()-OneCount;
        }
        int minOp=INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            int op=0;
            int g=nums[i];
            for(int j=i+1;j<nums.size();j++){
                g = gcd(g,nums[j]);
                op++;
                if(g==1) break;
            }
            if(g==1) minOp = min(op,minOp);
        }
        
        if(minOp!=INT_MAX){
            return nums.size()-1+minOp;
        }else return -1;
    }
};