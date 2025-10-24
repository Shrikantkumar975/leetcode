class Solution {
public:
    string reverseWords(string s) {
        string word="";
        vector<string> v;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' && word.size()!=0){
                v.push_back(word);
                word="";
            }else if(s[i]==' ' && word.size()==0){
                continue;    
            }else{
                word+=s[i];
            }
        }
        if(word.size()>0){
        int i=0;
        string l="";
        while(i<word.length() && word[i]!=' '){
            l+=word[i++];
        }
        v.push_back(l);
        word="";
        }

        reverse(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++){
            word+=v[i]+" ";
        }
        word+=v[v.size()-1];

        return word;
    }
};