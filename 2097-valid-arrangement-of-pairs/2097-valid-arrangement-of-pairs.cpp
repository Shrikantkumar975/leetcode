class Solution {
public:
    vector<int> path;

    void dfs(int u,unordered_map<int,vector<int>> &mpp){
        while(!mpp[u].empty()){
            int v = mpp[u].back();
            mpp[u].pop_back();
            dfs(v, mpp);
        }
        path.push_back(u);
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> mpp;
        unordered_map<int,int> indegree;
        unordered_map<int,int> outdegree;

        for(auto &t: pairs){
            int curr= t[0];
            int next=t[1];
            indegree[next]=0;
            outdegree[next]=0;
            indegree[curr]=0;
            outdegree[curr]=0;
        }

        for(auto &t: pairs){
            int curr= t[0];
            int next=t[1];

            mpp[curr].push_back(next);
            indegree[next]++;
            outdegree[curr]++;
        }

        int startNode = -1;

        for(auto &m: mpp){
            if(outdegree[m.first] - indegree[m.first] == 1){
                startNode=m.first;
                break;
            }
        }

        if(startNode == -1){
            startNode = pairs[0][0];
        }

        dfs(startNode,mpp);
        reverse(path.begin(),path.end());
        vector<vector<int>> ans;
        
        for(int i=0;i<path.size()-1;i++){
            ans.push_back({path[i],path[i+1]});
        }

        return ans;
    }
};