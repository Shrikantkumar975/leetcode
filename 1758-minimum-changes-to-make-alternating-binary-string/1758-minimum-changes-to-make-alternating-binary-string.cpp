class Solution {
public:
    int minOperations(string s) {
        int pattern1 = 0; // 010101...
        int pattern2 = 0; // 101010...

        for(int i = 0; i < s.size(); i++) {

            if(s[i] != (i % 2 == 0 ? '0' : '1'))
                pattern1++;

            if(s[i] != (i % 2 == 0 ? '1' : '0'))
                pattern2++;
        }

        return min(pattern1, pattern2);
    }
};