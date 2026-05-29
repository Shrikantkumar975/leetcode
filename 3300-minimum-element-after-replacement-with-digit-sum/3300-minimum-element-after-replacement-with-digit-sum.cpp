class Solution {
public:
    int reduce(int a){
        int ans=0;
        while(a){
            ans+=a%10;
            a/=10;
        }

        return ans;
    }

    int minElement(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=reduce(nums[i]);
        }

        return *min_element(nums.begin(),nums.end());
    }
};