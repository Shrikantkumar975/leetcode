class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> stored(26,-1);

        for(int i=0;i<s.size();i++){
            stored[s[i]-'a']=i;
        }

        stack<char> st;
        vector<bool> visited(26, false);

        int i=0;
        while(i<s.size()){

            if(visited[s[i]-'a']){
                i++;
                continue;
            }
            
            while(!st.empty() && st.top()>s[i]){
                if(stored[st.top()-'a']>i){
                    visited[st.top()-'a']=false;
                    st.pop();
                }else{
                    break;
                }
            }
            st.push(s[i]);
            visited[s[i]-'a']=true;
            
            i++;
        }

        string s1="";

        while(!st.empty()){
            s1+=st.top();
            st.pop();
        }

        reverse(s1.begin(),s1.end());

        return s1;
    }
};