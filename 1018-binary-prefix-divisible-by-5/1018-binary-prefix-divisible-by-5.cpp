class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int num = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Build the binary number incrementally
            num = ((num << 1) + nums[i]) % 5;
            result.push_back(num == 0);
        }

        return result;
    }
};
