class Solution {
public:

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int INF=1e8;
        vector<vector<int>> grid(26,vector<int>(26,INF));

        for (int i = 0; i < 26; i++)
            grid[i][i] = 0;


        for(int i=0;i<original.size();i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';
            int w=cost[i];

            grid[u][v] = min(grid[u][v], w);
        }

        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    if (grid[j][i] < INF && grid[i][k] < INF) 
                    grid[j][k] = min(grid[j][k],grid[j][i] + grid[i][k]);
                }
            }
        }

        long long ans=0;

        for(int i=0;i<source.size();i++){
            int u = source[i]-'a';
            int v = target[i]-'a';

            if (grid[u][v] == INF)
                return -1;
            ans+=grid[u][v];
        }

        return ans;
    }
};