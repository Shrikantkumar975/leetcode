class Solution {
public:
    int isIncreasing(vector<int> &nums,int start,int end){
        for(int i=start;i<end;i++){
            if(nums[i+1] <= nums[i]) return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        if(2*k > nums.size()) return false;

        for(int start = 0;start+2*k <= n;start++){
            int first = isIncreasing(nums,start,start+k-1);
            int second = isIncreasing(nums,start+k,start+2*k-1);

            if(first == 1 && second == 1) return true;
        }
        return false;
    }
};
