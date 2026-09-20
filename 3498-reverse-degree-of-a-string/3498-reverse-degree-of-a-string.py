class Solution:
    def reverseDegree(self, s: str) -> int:
        dp={}

        for i in range(26):
            dp[chr(i+97)] = 26-i
        
        ans=0

        for c in range(len(s)):
            ans+=dp[s[c]]*(c+1)
        
        return ans
        
