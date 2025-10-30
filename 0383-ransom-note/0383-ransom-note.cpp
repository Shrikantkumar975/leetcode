class Solution {
public:
    bool canConstruct(string s, string t) {
        vector<int> st(26,0);
        vector<int> tt(26,0);

        for(char c: s){
            st[c-'a']++;
        }
        for(char c: t){
            tt[c-'a']++;
        }

        for(int i=0;i<26;i++){
            if(st[i]>tt[i]){
                return false;
            }
        }

        return true;
    }
};