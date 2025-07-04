class Solution {
public:
    void updateString(bool a,string &word){
        string s="";
        if(a){
            for(int i=0;i<word.length();i++){
                int ch = word[i] - 'a';
                ch++;
                ch%=26;
                s+=char('a'+ch);
            }
        }else{
            s+=word;
        }
        word+=s;
    }

    char kthCharacter(long long k, vector<int>& operations) {
        string word ="a";
        for(int i=0;i<operations.size();i++){
            updateString(operations[i],word);
        }

        return word[k-1];
    }
};