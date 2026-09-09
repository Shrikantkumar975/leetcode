class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;

        int i = 0 ;
        while(i<nums.size()-1){
            if(abs(nums[i])<abs(nums[i+1])){
                break;
            }
            i++;
        }
        int j = i+1;

        while(i>=0 && j<nums.size()){
            if(abs(nums[i]) <= abs(nums[j])){
                ans.push_back(nums[i]*nums[i]);
                i--;
            }else{
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
        }

        while(i>=0){
            ans.push_back(nums[i]*nums[i]);
            i--;
        }

        while(j<nums.size()){
            ans.push_back(nums[j]*nums[j]);
            j++;
        }

        return ans;
    }
};