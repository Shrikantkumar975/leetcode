class Solution {
public:
    bool isPalindrome(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;

            i++;
            j--;
        }

        return true;
    }

    void dfs(string s, vector<vector<string>>& res, vector<string> temp,
             int idx) {
        if(idx==s.size()){
            res.push_back(temp);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (isPalindrome(s,idx,i)) {
                temp.push_back(s.substr(idx, i-idx+1));
                dfs(s,res,temp,i+1);
                temp.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;

        dfs(s, res,v,0);

        return res;
    }
};