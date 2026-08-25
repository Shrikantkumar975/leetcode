class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;

        for(int a: nums){
            mpp[a]=1;
        }

        int curr = k;
        while(curr<200){
            if(mpp.find(curr)==mpp.end()) break;
            
            curr+=k;
        }

        return curr;

    }
};