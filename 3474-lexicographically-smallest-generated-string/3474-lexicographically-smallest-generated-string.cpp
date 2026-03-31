class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        string s(n+m-1,'0');

        for(int i=0;i<n;i++){
            if(str1[i]=='T'){
                int k=0;
                for(int j=i;j<i+m;j++){
                    if(s[j]=='0' || s[j]==str2[k]) s[j]=str2[k];
                    else return "";
                    k++;
                }
            }
        }
        vector<bool> v(s.size(),false);

        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                s[i]='a';
                v[i]=true;
            }
        }

        for(int i=0;i<n;i++){
            if(str1[i]=='F'){
                if(s.substr(i,m)==str2){
                    int ch = false;
                    for(int j=i+m-1;j>=i;j--){
                        if(v[j]==true){
                            s[j]++;
                            ch=true;
                            v[j]=false;
                            break;
                        }
                    }
                    if(ch==false) return "";
                }
            }
        }

        return s;
    }
};