class Solution {
public:
    int minMoves(vector<int>& nums) {
        int totalMoves=0;

        int mn = *min_element(nums.begin(),nums.end());

        for(int a: nums){
            totalMoves+=a-mn;
        }

        return totalMoves;
    }
};