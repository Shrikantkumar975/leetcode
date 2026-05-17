class Solution {
public:
    void dfs(vector<int>& arr,int curr,bool &ans,vector<int> &visited){
        if(ans || curr>=arr.size() || curr<0 || visited[curr]) return;

        if(arr[curr]==0){
            ans=true;
            return;
        }

        visited[curr]=1;

        dfs(arr,curr+arr[curr],ans,visited);
        dfs(arr,curr-arr[curr],ans,visited);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> visited(arr.size(),0);
        bool ans=false;
        
        dfs(arr,start,ans,visited);
        return ans;
    }
};