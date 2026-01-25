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
            int col = 1;
            if(color[i]==0){
                queue<int> q;
                q.push(i);
                color[i] = col;
                while(!q.empty()){
                    int size = q.size();

                    while(size--){
                        int newCol = 3-col;
                        int u = q.front();
                        q.pop();
                        
                        for(int &v: graph[u]){
                            if(color[v] == col){
                                return false;
                            }
                            if(color[v]==0){
                                q.push(v);
                                color[v]=newCol;
                            }
                        }
                    }

                    col= 3-col;
                }
            }
        }

        return true;;

    }
};