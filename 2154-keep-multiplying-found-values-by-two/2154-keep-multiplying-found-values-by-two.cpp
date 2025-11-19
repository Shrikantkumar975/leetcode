class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        map<int,int> mpp;

        for(int a: nums){
            mpp[a]++;
        }

        while(mpp.find(original)!=mpp.end()){
            original*=2;
        }

        return original;

    }
};