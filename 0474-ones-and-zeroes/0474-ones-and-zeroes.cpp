class Solution {
public:
    pair<int,int> check(string& s,int m,int n){
        int a=0;
        int b=0;

        for(char ch: s){
            if(ch == '1') b++;
            else a++;
        }
        return {a,b};
    }

    int solve(vector<pair<int,int>>&count,int m, int n,int l){
        if(l==0) return 0;

        int take =0;
        if(count[l-1].first<=m && count[l-1].second<=n){
            take = 1 + solve(count,m-count[l-1].first,n-count[l-1].second,l-1);
        }

        int skip = solve(count,m,n,l-1);

        return max(take,skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int L = strs.size();
        vector<pair<int,int>> count;

        for(string &s: strs){
            count.push_back(check(s,m,n));
        }
        return solve(count,m,n,L);
    }
};