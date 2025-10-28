class Solution {
public:
    bool simulate(int i, vector<int> nums, int dir) {
        int n = nums.size();
        while (i >= 0 && i < n) {
            if (nums[i] > 0) {
                nums[i]--;
                dir *= -1; // change direction only if decremented
                i += dir;
            } else {
                i += dir; // keep moving
            }
        }

        for (int num : nums)
            if (num != 0) return false;
        return true;
    }

    int countValidSelections(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (simulate(i, nums, -1)) res++;
                if (simulate(i, nums, +1)) res++;
            }
        }
        return res;
    }
};
