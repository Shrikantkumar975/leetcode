class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<char> alpha(27,0);

        for(auto &c : brokenLetters){
            alpha[c-'a'] = 1;
        }

        vector<string> s;
        string p="";
        for(char c: text){
            if(c == ' '){
                s.push_back(p);
                p="";
            }else{
                p+=c;
            }
        }
        s.push_back(p);
        int count =0;

        for(int i=0;i<s.size();i++){
            int nf = 0;
            for(int j=0;j<s[i].size();j++){
                if(alpha[s[i][j] - 'a'] == 1){
                    nf=1;
                    break;
                }
            }
            if(nf==1) count++;
        }
        return s.size()-count;
    }
};