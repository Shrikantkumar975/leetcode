class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int maxi=0;
        int i=0;
        int j=0;

        while(j<s.size()){
            mpp[s[j]]++;

            while(j>i && mpp[s[j]]>1){
                mpp[s[i]]--;
                i++;
            }

            maxi = max(maxi,j-i+1);
            j++;
        }

        return maxi;
    }
};