// 1010
// 1000
// 1010

// 011
// 100
// 111

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 2) {
                result.push_back(-1);
                continue;
            }

            bool found = false;
            for (int j = 1; j < 32; j++) {
                if ((nums[i] & (1 << j)) > 0) {
                    continue;
                }
                int x = nums[i] ^ (1 << (j - 1));
                result.push_back(x);
                found = true;
                break;
            }

            if(!found) result.push_back(-1);
        }
        return result;
    }
};