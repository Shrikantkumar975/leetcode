class Solution {
public:
    int maxOperations(string s) {
        queue<int> q;

        int oneCount = 0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='1') oneCount++;
            else if(oneCount>0){
                    q.push(oneCount);
                    oneCount=0;
            }
        }

        int count =0;
        int prev =0;
        while(!q.empty()){
            int a = q.front();
            q.pop();
            count += prev + a;
            prev = prev + a;
        }

        return count;
    }
};