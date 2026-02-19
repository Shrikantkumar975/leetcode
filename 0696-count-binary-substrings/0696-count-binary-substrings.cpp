class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevGroup = 0;   // length of previous group
        int currGroup = 1;   // length of current group
        int ans = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                currGroup++;   // same character → increase current group
            } else {
                ans += min(prevGroup, currGroup);
                prevGroup = currGroup;
                currGroup = 1;
            }
        }

        // Add last pair
        ans += min(prevGroup, currGroup);

        return ans;
    }
};
