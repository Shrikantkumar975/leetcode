class Solution {
public:
    string capitalizeTitle(string title) {
        vector<string> s;
        string str ="";

        for(char ch : title){
            if(ch == ' '){
                s.push_back(str);
                str="";
            }
            else{
                if(ch>='A' && ch<='Z') ch+=32;
                str+=ch;
            }
        }

        s.push_back(str);

        for(string &s1 : s){
            if(s1.length()>2 && s1[0]>='a' && s1[0]<='z'){
                s1[0]-=32;
            }
        }

        string res ="";
        for(string &s1 : s){
            res+=s1+" ";
        }

        return res.substr(0,res.size()-1);
    }
};