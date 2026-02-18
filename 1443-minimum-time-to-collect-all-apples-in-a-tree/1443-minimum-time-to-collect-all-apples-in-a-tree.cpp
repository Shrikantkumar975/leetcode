class Solution {
public:
    int dfs(vector<vector<int>> &adj,unordered_set<int> &s,int u,int parent){
        int curr = 0;
        for(int v: adj[u]){
            if(v==parent) continue;
            int n = dfs(adj,s,v,u);

            if(n > 0 || s.find(v) != s.end()) {
                curr +=n + 2;
            }
        }
        return curr; 
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<vector<int>> adj(n);

        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_set<int> s;
        for(int i=0;i<n;i++){
            if(hasApple[i]) s.insert(i);
        }

        int ans = dfs(adj,s,0,-1);

        return ans;
    }
};