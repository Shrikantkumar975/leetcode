class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int sum=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X')){
                switch (s[i+1]){
                    case 'V':
                    sum+=m['V']-m['I'];
                    break;
                    case 'X':
                    sum+=m['X']-m['I'];
                    break;
                }
                i++;
            }
            else if(s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C')){
                switch (s[i+1]){
                    case 'L':
                    sum+=m['L']-m['X'];
                    break;
                    case 'C':
                    sum+=m['C']-m['X'];
                    break;
                }
                i++;
            }
            else if(s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M')){
                switch (s[i+1]){
                    case 'D':
                    sum+=m['D']-m['C'];
                    break;
                    case 'M':
                    sum+=m['M']-m['C'];
                    break;
                }
                i++;
            }else{
            sum+=m[s[i]];
            }
        }
        return sum;
    }
};