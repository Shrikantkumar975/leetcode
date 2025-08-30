class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for(int i=0;i<s.size();i++){
            int found = 0;
            while(!st.empty() && s[i] == st.top()){
                st.pop();
                found = 1;
            }

            if(found) continue;

            st.push(s[i]);
        }

        string res;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;

    }
};