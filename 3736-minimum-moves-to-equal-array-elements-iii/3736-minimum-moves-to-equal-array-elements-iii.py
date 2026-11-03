class Solution:
    def minMoves(self, nums: List[int]) -> int:
        maxi = max(nums)
        ans=0
        for a in nums:
            ans+=maxi-a
        
        return ans