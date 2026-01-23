class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0); 

        for(auto &edge: edges){
            indegree[edge[1]]++;
        }

        vector<int> cnt;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) cnt.push_back(i);
        }

        return cnt;
    }
};