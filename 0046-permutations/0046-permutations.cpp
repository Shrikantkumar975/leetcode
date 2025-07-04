class Solution {
public:
    void solve(vector<int> nums,vector<int> &temp,vector<vector<int>> &res,int start){
        if(temp.size()==nums.size()) {
            res.push_back(temp);
        }

        for(int i=0;i<nums.size();i++){
            int j=false;
            for(int k=0;k<temp.size();k++){
                if(temp[k]==nums[i]){
                    j=true;
                    break;
                }
            }
            if(j) continue;

            temp.push_back(nums[i]);
            solve(nums,temp,res,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        vector<int> temp;

        solve(nums,temp,res,0);

        return res;
    }
};