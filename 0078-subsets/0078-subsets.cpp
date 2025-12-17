class Solution {
public:
    void fun(vector<int> &nums,vector<vector<int>>&res,int i,vector<int> temp){
        if(i==nums.size()){
            res.push_back(temp);
            return;
        }

        fun(nums,res,i+1,temp);
        temp.push_back(nums[i]);
        fun(nums,res,i+1,temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;

        vector<int> temp;

        fun(nums,res,0,temp);

        return res;
    }
};