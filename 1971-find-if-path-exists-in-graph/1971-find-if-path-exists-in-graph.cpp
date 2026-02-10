class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        if(source == destination) return true;

        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(n,0);

        queue<int> q;
        q.push(source);
        visited[source]=1;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int a: adj[u]){
                if(a==destination) return true;
                if(!visited[a]){
                    q.push(a);
                    visited[a]=1;
                }
            }
        }

        return false;
    }
};