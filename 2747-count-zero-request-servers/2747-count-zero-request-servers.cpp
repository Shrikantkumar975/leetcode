class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        int k = logs.size();
        
        sort(logs.begin(),logs.end(),[](const auto &a,const auto &b){
            return a[1]<b[1];
        });

        vector<int> ans(queries.size(),0);

        vector<vector<int>> que;
        for(int i=0;i<queries.size();i++){
            que.push_back({queries[i],i});
        }

        sort(que.begin(),que.end());
        int i=0;
        int j=0;
        unordered_map<int,int> mpp;

        for(auto curr: que){
            int q = curr[0];
            int on = curr[1];

            int l = q-x;
            int r=q;
            
            while(j<k && logs[j][1]<=r){
                mpp[logs[j][0]]++;
                j++;
            }

            while(i<j && logs[i][1]<l){
                if(mpp.find(logs[i][0])!=mpp.end()){
                    mpp[logs[i][0]]--;
                    if(mpp[logs[i][0]]==0) mpp.erase(logs[i][0]);
                }
                i++;
            }

            // j=i;


            ans[on] = n- mpp.size();
        }

        return ans;
    }
};