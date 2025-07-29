class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int left = 0, right = 0, maxLen = 0;

        while (right < s.size()) {
            if (m.count(s[right])) {
                left = max(left, m[s[right]] + 1);
            }
            m[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};
