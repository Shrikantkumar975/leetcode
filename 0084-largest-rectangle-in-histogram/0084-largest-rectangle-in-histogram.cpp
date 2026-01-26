class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> findPSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);
        for(int i=0;i<heights.size();i++){
            int l = i - pse[i];
            int r = nse[i] - i;
            int area = (l+r-1)*heights[i];
            maxi =max(maxi,area);  
        }

        return maxi;
    }
};