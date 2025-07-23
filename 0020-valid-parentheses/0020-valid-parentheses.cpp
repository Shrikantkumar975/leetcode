class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;

        int i=0;
        while(i<s.size()){
            if(s[i] == '(' || s[i] == '[' || s[i]=='{'){
                s1.push(s[i]);
            }else{
                if(s1.empty()) return false;
                if(s[i] == ')' && s1.top() == '('){
                    s1.pop();
                }
                else if(s[i] == ']' && s1.top() == '['){
                    s1.pop();
                }
                else if(s[i] == '}' && s1.top() == '{'){
                    s1.pop();
                }
                else {
                    return false;
                }
            }
            i++;
        }
        return s1.empty();
    }
};