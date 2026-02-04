class Solution {
public:
    int myAtoi(string s) {
        long long num =0;
        char ch = ' ';
        int flag=0;

        int i=0;
        while(i < s.size() && s[i]==' '){
            i++;
        }

        while(i<s.size()){
            char c=s[i];
            if((c=='+' || c=='-') && ch==' ' && flag==0){
                ch = c;
            }else if(c>='0' && c<='9'){

                 if (num > (LLONG_MAX - (c-'0')) / 10) {
                    return (ch == '-') ? INT_MIN : INT_MAX;
                }

                num=num*10+(c-'0');
                flag=1;
            }else break;
            i++;
        }

        if(ch == '-') num = -num;

        if(num<INT_MIN) return INT_MIN;

        if(num>INT_MAX) return INT_MAX;

        return num;
    }
};