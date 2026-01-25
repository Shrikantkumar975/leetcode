class Solution {
public:
    bool dfs(vector<vector<int>> &graph,vector<int> &color,int u,int col){
        color[u] = col;

        int newCol = col==1?2:1;
        for(int &v: graph[u]){
            if(color[v] == col){
                return false;
            }

            if(color[v]==0){
                if(!dfs(graph,color,v,newCol)){
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(graph.size(),0);

        for(int i=0;i<V;i++){
            if(color[i]==0){
                if(!dfs(graph,color,i,1))
                    return false;
            }
        }

        return true;;

    }
};