class Solution {
public:
    vector<string> path;

    void dfs(string u,unordered_map<string,vector<string>> &mpp){
        while(!mpp[u].empty()){
            string v = mpp[u].back();
            mpp[u].pop_back();
            dfs(v, mpp);
        }
        path.push_back(u);
    }

    vector<string> findItinerary(vector<vector<string>>& pairs) {
        unordered_map<string,vector<string>> mpp;
        unordered_map<string,int> indegree;
        unordered_map<string,int> outdegree;

        for(auto &t: pairs){
            string curr= t[0];
            string next=t[1];
            indegree[next]=0;
            outdegree[next]=0;
            indegree[curr]=0;
            outdegree[curr]=0;
        }

        for(auto &t: pairs){
            string curr= t[0];
            string next=t[1];

            mpp[curr].push_back(next);
            indegree[next]++;
            outdegree[curr]++;
        }

        string startNode = "JFK";

        for(auto &it : mpp){
            sort(it.second.begin(), it.second.end(), greater<string>());
        }

        // for(auto &m: mpp){
        //     if(outdegree[m.first] - indegree[m.first] == 1){
        //         startNode=m.first;
        //         break;
        //     }
        // }
        // if(startNode == ""){
        //     startNode = pairs[0][0];
        // }



        dfs(startNode,mpp);
        reverse(path.begin(),path.end());

        // vector<vector<string>> ans;
        
        // for(int i=0;i<path.size()-1;i++){
        //     ans.push_back({path[i],path[i+1]});
        // }

        return path;
    }
};