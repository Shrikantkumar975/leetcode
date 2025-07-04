class Solution {
public:
    bool checkPalindrome(string s){
        string a = s;
        reverse(a.begin(),a.end());
        if(a==s) return true;
        return false;
    }

    void solve(vector<vector<string>> &res, vector<string> &ans, int start, string &s){
        if (start == s.length()) {
            res.push_back(ans);
            return;
        }

        for (int i = start; i < s.length(); i++) {
            string sub = s.substr(start, i - start + 1);
            if (checkPalindrome(sub)) {
                ans.push_back(sub);
                solve(res, ans, i + 1, s);
                ans.pop_back();  // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;

        solve(res,ans,0,s);

        return res;

    }
};