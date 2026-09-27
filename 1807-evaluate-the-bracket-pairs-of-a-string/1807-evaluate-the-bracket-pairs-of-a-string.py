class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        dist = {}
        res=[]

        for a,b in knowledge:
            dist[a]=b
        i=0
        while i < len(s):
            if(s[i]=='('):
                j=i+1
                while(s[j]!=')'):
                    j+=1
                
                val = dist.get(s[i+1:j], None)
                if val is not None:
                    res.append(val)
                else:
                    res.append("?")
                i=j+1
            else:
                res.append(s[i])
                i+=1
        
        return "".join(res)