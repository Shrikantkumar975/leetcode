class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if(asteroids.size()==1) return {asteroids[0]};
        stack<int> st;
        st.push(asteroids[0]);

        int i=1;
        while(i<asteroids.size()){
            int curr=asteroids[i];
            int flag=false;
            while(!st.empty() && curr<0){
                int a = st.top();
                st.pop();

                if(a==abs(curr)){
                    flag=true;
                    break;
                }

                if(a!=abs(curr)){
                    if(a>abs(curr)) curr = a;
                }
            }
            if(flag==0) st.push(curr);
            i++;
        }

        vector<int> v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }

        reverse(v.begin(),v.end());

        return v;
    }
};