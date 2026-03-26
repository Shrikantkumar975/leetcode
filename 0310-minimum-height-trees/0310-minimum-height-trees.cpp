class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        if(n==1) return {0};

        // if(n==2) return {1,1};

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            indegree[v]++;
            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;

        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==1) q.push(i);
        }

        while(n>2){
            int size = q.size();

            n-=size;

            while(size--){
                int curr = q.front();
                q.pop();

                for(int a: adj[curr]){
                    indegree[a]--;
                    if(indegree[a]==1){
                        q.push(a);
                    }
                }
            }
        }

        vector<int> result;

        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};