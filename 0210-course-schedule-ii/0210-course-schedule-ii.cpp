class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        vector<int> todo;

        for(auto edge : prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int u =q.front();
            q.pop();
            todo.push_back(u);

            for(int &v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }        

        if(todo.size()==numCourses){
            reverse(todo.begin(),todo.end());
            return todo;
        }

        return {};
    }
};