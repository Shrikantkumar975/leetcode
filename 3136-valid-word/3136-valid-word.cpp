class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return 0;
        int v=0;
        int c=0;
        for(char ch:word){
            if(isalpha(ch)) {
                char lower = tolower(ch);
                if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                    v++;
                else
                    c++;
            }
            else if(isdigit(ch)) {
                continue;
            }
            else {
                return false;
            }
        }

        if(v>0 && c>0) return true;
        else return false;
    }
};