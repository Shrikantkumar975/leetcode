class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorAll =0;

        for(int num:nums) xorAll^=num;

        long long diff = xorAll & -xorAll;
        int x=0,y=0;
        for(int num: nums){
            if(diff & num) x^=num;
            else y^=num;
        }

        return {x,y};
    }
};