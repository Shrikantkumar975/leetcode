class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int maxi = strs[0].size();

        for(int i=1;i<strs.size();i++){
            int curr=0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]==strs[i-1][j]) curr++;
                else break;
            }
            maxi=min(maxi,curr);
        }

        return strs[0].substr(0,maxi);
    }
};