class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<int> reach(s.size(),0);

        if(s[s.size()-1] != '0') return false;

        queue<int> q;

        q.push(0);
        reach[0]=1;

        int far=0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            int mini = max(curr+minJump,far+1);
            int maxi = min(curr+maxJump,(int)s.size()-1);

            for(int i=mini;i<=maxi;i++){
                if(reach[i]) continue;

                if(s[i]=='0'){
                    if(i==s.size()-1) return true;
                    reach[i]=1;
                    q.push(i);
                }
            }

            far = maxi;
        }

        return reach[s.size()-1];
    }
};