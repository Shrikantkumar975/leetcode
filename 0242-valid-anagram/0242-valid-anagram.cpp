class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char,int> m;

        for(char ch : s){
            m[ch]++;
        }

        for(char ch : t){
            if(m[ch] == 0) return false;

            m[ch]--;
        }

        return true;
    }
};