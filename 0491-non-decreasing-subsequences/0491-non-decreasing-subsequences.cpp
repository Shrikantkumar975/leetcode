class Solution {
public:
    void fillRes(vector<int> &nums,vector<int> &temp,vector<vector<int>> &res,int start){
        if(temp.size()>=2)  res.push_back(temp);;

        if(start==nums.size()) return;

        unordered_set<int> used;

        for(int i = start; i < nums.size(); i++) {

            // skip duplicate numbers at same recursion depth
            if(used.count(nums[i])) continue;

            // check non-decreasing condition
            if(temp.empty() || nums[i] >= temp.back()) {

                used.insert(nums[i]);  // mark used at this level

                temp.push_back(nums[i]);
                fillRes(nums,temp, res,i+1);
                temp.pop_back();       // backtrack
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>temp;

        fillRes(nums,temp,res,0);

        return res;

    }
};