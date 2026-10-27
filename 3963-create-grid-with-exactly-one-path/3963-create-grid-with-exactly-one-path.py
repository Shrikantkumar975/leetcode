class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        arr = []
        # arr.append(list('.' for i in range(m)))

        for i in range(m):
            curr=[]
            for j in range(n):
                if(j==n-1 or i==0):
                    curr.append('.')
                else:
                    curr.append('#')
            arr.append("".join(curr))
        
        return arr