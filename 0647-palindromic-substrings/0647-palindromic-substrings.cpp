class Solution {
public:
    int count=0;

    bool validPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(validPalindrome(s,i,j)) count++;
            }
        }

        return count;
    }
};