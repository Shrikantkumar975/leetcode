class Solution { // Kadane Algorithms
public:
    int maxSubArray(vector<int>& nums) {
            int m = INT_MIN;
            int currS = 0;

            for(int i=0;i<nums.size();i++){
                currS+=nums[i];

                if(currS>m){
                    m = currS;
                }

                if(currS < 0) currS = 0;
            } 

            return m;
    }
};