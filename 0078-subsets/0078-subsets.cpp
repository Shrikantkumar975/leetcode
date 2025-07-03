class Solution {
public:
    void fun(vector<int> &nums,int start,vector<int> temp,vector<vector<int>> &res){
        res.push_back(temp);
        for(int ji= start;ji<nums.size();ji++){
            temp.push_back(nums[ji]);
            fun(nums,ji+1,temp,res);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>temp;
        fun(nums,0,temp,res);
        return res;
    }
};