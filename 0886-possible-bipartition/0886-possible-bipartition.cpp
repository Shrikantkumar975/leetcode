class Solution {
public:
    bool dfs(vector<vector<int>> &adj,int i, int col,vector<int> &visited){
        visited[i]=col;

        int newCol = 3-col;
        for(int v: adj[i]){
            if(visited[v]==col) return false;

            if(!visited[v]){
                if(!dfs(adj,v,newCol,visited)) return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);

        for(auto &edge : dislikes){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n+1,0);
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                if(!dfs(adj,i,1,visited)){
                    return false;
                }
            }
        }

        return true;
    }
};