class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                count++;
            }
        }
        if(count==0) return false;
        return true;
    }
};