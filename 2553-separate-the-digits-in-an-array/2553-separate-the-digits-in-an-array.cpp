class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        stack<int> st;

        for(auto i: nums){
            while(i){
                st.push(i%10);
                i/=10;
            }

            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
        }

        return ans;
    }
};