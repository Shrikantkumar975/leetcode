class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        
        unordered_map<char,int> mpp;

        for(char c: s){
            mpp[c]++;
        }
        
        for(char c: t){
            mpp[c]--;
            if(mpp[c]==0) mpp.erase(c);
        }

        return mpp.size()==0;
    }
};