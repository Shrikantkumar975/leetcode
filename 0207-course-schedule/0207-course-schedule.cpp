class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);

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

        int count=0;

        while(!q.empty()){
            int u =q.front();
            q.pop();
            count++;

            for(int &v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }        

        return count==numCourses;
    }
};