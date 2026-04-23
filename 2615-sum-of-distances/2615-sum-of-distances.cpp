class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,pair<int,int>> mpp;
        vector<long long> ans(nums.size());

        for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i])!=mpp.end()){
                int prev = mpp[nums[i]].first;
                int prevCount = mpp[nums[i]].second;
                ans[i] = ans[prev] + (i-prev)*prevCount; 
                mpp[nums[i]] = {i,prevCount+1};   
            }else{
                ans[i]=0;
                mpp[nums[i]]={i,1};
            }
        }

        mpp.clear();
        vector<long long> ans2(nums.size());

        for(int i=nums.size()-1;i>=0;i--){
            if(mpp.find(nums[i])!=mpp.end()){
                int next = mpp[nums[i]].first;
                int nextCount = mpp[nums[i]].second;
                ans2[i] = ans2[next] + abs(next-i)*nextCount; 
                mpp[nums[i]] = {i,nextCount+1};   
            }else{
                ans2[i]=0;
                mpp[nums[i]]={i,1};
            }
        }

        for(int i=0;i<nums.size();i++){
            ans[i]+=ans2[i];
        }



        return ans;
    }
};