class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int res=0;

        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int currPop = st.top();
                st.pop();

                int pse = st.empty()?-1:st.top();

                res = max(res,heights[currPop]*(i-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int currPop = st.top();
            st.pop();

            int pse = st.empty()?-1:st.top();

            res = max(res,heights[currPop]*(n-pse-1));
        }

        return res;
    }
};