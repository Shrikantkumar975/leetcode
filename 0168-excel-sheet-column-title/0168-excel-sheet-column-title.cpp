class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";
        while (columnNumber > 0) {
            columnNumber--; // shift to 0-indexed
            int rem = columnNumber % 26;
            s += ('A' + rem);
            columnNumber /= 26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};