class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        
        if(n == 0) return 0; // empty needle
        
        for(int i = 0; i <= h - n; i++) {
            int j = 0;
            while(j < n && haystack[i + j] == needle[j]) {
                j++;
            }
            if(j == n) return i; // full match found
        }
        return -1; // not found
    }
};
