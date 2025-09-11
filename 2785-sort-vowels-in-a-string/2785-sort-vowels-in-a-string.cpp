class Solution {
public:
    string sortVowels(string s) {
        vector<int> v;
        vector<char> ch;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U') {
                ch.push_back(s[i]);
                v.push_back(i);
            }
        }

        sort(ch.begin(),ch.end());

        for(int i=0;i<v.size();i++){
            s[v[i]] =ch[i];
        }

        return s;
    }
};