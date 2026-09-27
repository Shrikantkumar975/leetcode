class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        
        for(char c: s){
            if(c==')'){
                string s1="";
                while(st.top()!='('){
                    s1+=st.top();
                    st.pop();
                }
                st.pop();

                for(char c1: s1){
                    st.push(c1);
                }
            }else{
                st.push(c);
            }
        }

        stack<char> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }

        string ans="";
        while(!temp.empty()){
            ans+=temp.top();
            temp.pop();
        }

        return ans;
    }
};