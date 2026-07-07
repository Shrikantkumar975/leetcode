class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long newNum = 0;
        stack<int> st;

        while(n){
            int curr = n%10;
            if(curr>=1 && curr<=9){
                st.push(curr);
                sum+=curr;
            }

            n/=10;
        }

        while(!st.empty()){
            newNum = newNum*10 + st.top();
            st.pop();
        }

        return newNum*sum;

    }
};