class Solution {
public:
    int ans=0;
    void solve(vector<vector<int>> &requests,vector<int> &v,int count,int start){
        if(start == requests.size()){
            for(int i=0;i<v.size();i++){
                if(v[i]!=0) return;
            }
            ans = max(ans,count);
            return;
        }

        int curri = requests[start][0];
        int currj = requests[start][1];

        v[curri]--;
        v[currj]++;
        solve(requests,v,count+1,start+1);
        v[curri]++;
        v[currj]--;
        solve(requests,v,count,start+1);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> v(n,0);

        solve(requests,v,0,0);

        return ans;
    }
};