class Solution {
public:
    string processStr(string s) {
        string str = "";

        for(char c: s){
            if(c=='*' ){ if(!str.empty()) str.pop_back();
            }else if(c=='#') str+=str;
            else if(c=='%'){ if(!str.empty()) reverse(str.begin(),str.end());
            }else str+=c;
        }

        return str;
    }
};