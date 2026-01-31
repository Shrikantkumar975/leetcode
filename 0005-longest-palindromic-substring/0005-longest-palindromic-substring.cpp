class Solution {
public:
    bool checkPalindrome(string &s,int i,int j){
        
        while(i<=j){
            if(s[i]==s[j]){
                i++;j--;
            }else{
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        string s1 ="";
        int currI=0;
        int currJ=0;
        int maxi=1;
        if(s.length()==1) return s;
        for(int i=0;i<s.length()-1;i++){
            for(int j=i;j<s.length();j++){
                if(checkPalindrome(s,i, j)){
                    if(j-i+1>maxi){
                        maxi=j-i;
                        currI=i;
                        currJ=j;
                    }
                }
            }
        }
        return s.substr(currI,currJ-currI+1);
    }
};