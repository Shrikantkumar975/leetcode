class Solution {
public:

    void solve(int n,vector<string> &res,int open,int close,string s){
        if(close == n){
            res.push_back(s);
            return;
        }

        if(open<n){
            solve(n,res,open+1,close,s+'(');
        }

        if(open>close){
            solve(n,res,open,close+1,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s="";
        solve(n,res,0,0,s);

        return res;
    }
};