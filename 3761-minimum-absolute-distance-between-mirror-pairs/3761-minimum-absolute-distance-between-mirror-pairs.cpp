class Solution {
public:
    int reverseInt(int a){
        int b = 0;

        while(a){
            b=b*10 + a%10;
            a/=10;
        }

        return b;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int ans=INT_MAX;

        for(int i=nums.size()-1;i>=0;i--){
            int curr = reverseInt(nums[i]);
            if(mpp.find(curr)!=mpp.end()){
                ans= min(ans,abs(i - mpp[curr]));
            }
            mpp[nums[i]]=i;
        }

        return ans==INT_MAX? -1:ans;
    }
};