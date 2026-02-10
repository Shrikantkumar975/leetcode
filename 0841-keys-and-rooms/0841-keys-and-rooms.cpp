class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(),0);

        queue<int> q;
        q.push(0);
        visited[0]=1;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v: rooms[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=1;
                }
            }
        }

        for(int a: visited){
            if(a==0) return false;
        }

        return true;
    }
};