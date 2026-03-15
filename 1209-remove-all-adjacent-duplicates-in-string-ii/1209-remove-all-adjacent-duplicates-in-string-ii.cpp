class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;

        for(char c: s){
            int count=1;
            if(!st.empty() && st.top().first==c){
                count+=st.top().second;
                st.pop();
            }
            if(count==k) continue;
            st.push({c,count});
        }

        stack<char> st2;
        while(!st.empty()){
            auto [a,b] = st.top();
            st.pop();
            while(b){
                st2.push(a);
                b--;
            }
        }

        string ans="";

        while(!st2.empty()){
            ans+=st2.top();
            st2.pop();
        }

        return ans;

    }
};