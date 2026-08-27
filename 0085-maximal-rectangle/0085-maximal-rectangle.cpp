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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi = 0;
        vector<int> mat(matrix[0].size(),0);

        for(int i=0;i<matrix.size();i++){
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == '0')
                    mat[j] = 0;
                else
                    mat[j]++;
            }
            maxi = max(maxi,largestRectangleArea(mat));
        }
        return maxi;
    }
};