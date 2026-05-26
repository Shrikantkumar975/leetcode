class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> small(26,0);
        vector<int> big(26,0);

        for(char c: word){
            if(c>='a' && c<='z') small[c-'a']=1;
            if(c>='A' && c<='Z')big[c-'A']=1;
        }

        int count=0;
        for(int i=0;i<=25;i++){
            if(big[i]==1 && small[i]==1) count++;
        }

        return count;
    }
};