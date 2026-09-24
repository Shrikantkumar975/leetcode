class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        
        for i in range(len(nums)):
            sum=0
            num=[int(d) for d in str(nums[i])]
            for a in num:
                sum+=a

            if sum==i:
                return i
        return -1