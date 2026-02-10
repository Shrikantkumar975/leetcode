class Solution {
public:
    void dfs(vector<vector<int>> &stones, vector<int> &visited, int curr){
        visited[curr]=1;

        for(int i=0;i<stones.size();i++){
            if(!visited[i] && (stones[i][0]==stones[curr][0] || stones[i][1]==stones[curr][1])){
                dfs(stones,visited,i);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        vector<int> visited(stones.size(),0);
        int count=0;

        for(int i=0;i<stones.size();i++){
            if(!visited[i]){
                count++;
                dfs(stones,visited,i);
            }
        }

        return stones.size() - count;
    }
};