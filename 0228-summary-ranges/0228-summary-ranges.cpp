class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> s;
        if (nums.empty()) return s;
        
        vector<int> v;
        v.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1){
                v.push_back(nums[i]);
            }else{
                if(v.size()==1) s.push_back(to_string(v[0]));
                else s.push_back(to_string(v[0])+"->"+to_string(v[v.size()-1]));
                v.clear();
                v.push_back(nums[i]);
            }
        }

        if(v.size()==1) s.push_back(to_string(v[0]));
        else s.push_back(to_string(v[0])+"->"+to_string(v[v.size()-1]));

        return s;
    }
};