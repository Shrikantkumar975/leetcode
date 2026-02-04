class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans=0;
        for(int a: left){
            ans=max(ans,a);
        }
        for(int a: right){
            ans=max(ans,n-a);
        }
        return ans;
    }
};