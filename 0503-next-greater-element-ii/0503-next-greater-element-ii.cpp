class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> v(nums.size());

        v[nums.size()-1] = -1;
        st.push(nums[nums.size()-1]);

        for(int i=nums.size()-2;i>=0;i--){

            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }

            if(st.empty()){
                v[i] = -1;
                st.push(nums[i]);
            }else{
                v[i] = st.top();
                st.push(nums[i]);
            }

        }

        for(int i=nums.size()-1;i>=0;i--){

            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }

            if(st.empty()){
                v[i] = -1;
                st.push(nums[i]);
            }else{
                v[i] = st.top();
                st.push(nums[i]);
            }

        }
        return v;
    }
};