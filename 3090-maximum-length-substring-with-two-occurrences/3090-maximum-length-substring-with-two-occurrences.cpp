class Solution {
public:
    int maximumLengthSubstring(string s) {
        map<char,int> mpp;

        int i=0;
        int j=0;
        int maxi=0;

        while(j<s.size()){
            mpp[s[j]]++;
            while(mpp[s[j]]>2){
                mpp[s[i]]--;
                i++;
            }

            maxi = max(maxi,j-i+1);
            j++;
        }

        return maxi;
    }
};