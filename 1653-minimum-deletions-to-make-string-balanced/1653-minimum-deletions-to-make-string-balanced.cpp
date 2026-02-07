class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int i=0;
        int count=0;
        while(i<s.size()){
            if(s[i]=='b') st.push(s[i]);
            else if(s[i]=='a' && !st.empty() && st.top()=='b'){
                st.pop();
                count++;
            }else{
                st.push(s[i]);
            }

            i++;
        }

        return count;
    }
};