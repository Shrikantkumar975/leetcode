class Solution {
public:
    int countAsterisks(string s) {
        string newStr="";
        int count=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='|') count++;
            else if(count%2==0){
                newStr+=s[i];
            }
        }
    
        count=0;
        for(char c: newStr){
            if(c=='*') count++;
        }

        return count;
    }
};