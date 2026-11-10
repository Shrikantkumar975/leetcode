class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> v(n+1,0);
        v[0]=0;
        v[1]=costs[0]+1;

        if(n>1)
            v[2]=costs[1]+min(v[1]+1,v[0]+4);

        for(int i=3;i<=n;i++){
            v[i] = costs[i-1] + min(v[i-1]+1,min(v[i-2]+4,v[i-3]+9));
        }

        return v[n];
    }
};