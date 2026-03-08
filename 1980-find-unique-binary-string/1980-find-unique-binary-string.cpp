class Solution {
public:
    string ans="";

    void solve(string &curr,int n,set<string> &st,bool &found){
        if(found) return;

        if(curr.size()==n){
            if(st.find(curr)==st.end()){
                found=true;
                ans =curr;
            }
            return;
        }

        
        curr.push_back('1');
        solve(curr,n,st,found);
        curr.pop_back();

        curr.push_back('0');
        solve(curr,n,st,found);
        curr.pop_back();
    }


    string findDifferentBinaryString(vector<string>& nums) {
        set<string> st;

        for(string s: nums){
            st.insert(s);
        }

        int n = nums.size();
        bool found = false;

        string curr="";

        solve(curr,n,st,found);

        return ans;
    }
};