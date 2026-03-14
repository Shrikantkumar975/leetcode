class Solution {
public:

    void solve(unordered_map<char,vector<char>> &mpp,int idx,vector<string> &str,string s,string digits){
        if(idx==digits.size()){
            str.push_back(s);
            return;
        }

        for(auto m: mpp[digits[idx]]){
            s+=m;
            solve(mpp,idx+1,str,s,digits);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char,vector<char>> mpp;

        mpp['2']={'a','b','c'};
        mpp['3']={'d','e','f'};
        mpp['4']={'g','h','i'};
        mpp['5']={'j','k','l'};
        mpp['6']={'m','n','o'};
        mpp['7']={'p','q','r','s'};
        mpp['8']={'t','u','v'};
        mpp['9']={'w','x','y','z'};

        vector<string> str;

        string s="";
        int i=0;

        for(auto m: mpp[digits[i]]){
            s+=m;
            solve(mpp,i+1,str,s,digits);
            s.pop_back();
        }

        return str;
    }
};