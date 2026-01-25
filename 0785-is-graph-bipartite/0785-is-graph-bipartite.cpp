class Solution {
public:
    bool dfs(vector<vector<int>> &graph,vector<int> &color,int u,int col){
        color[u] = col;

        int newCol = 3-col;

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
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while(!q.empty()){
                    int size = q.size();

                    while(size--){
                        int u = q.front();
                        q.pop();
                        
                        for(int &v: graph[u]){
                            if(color[v] == color[u]){
                                return false;
                            }
                            if(color[v]==0){
                                q.push(v);
                                color[v]=3-color[u];
                            }
                        }
                    }
                }
            }
        }

        return true;;

    }
};