class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        if(heights.size()==1) return {0};
        int n=heights.size();

        stack<int> st;
        st.push(heights[n-1]);

        vector<int> ans(n,0);
        ans[n-2]=1;
        if(st.top()<=heights[n-2]){
            st.pop();
        }
        st.push(heights[n-2]);

        for(int i=n-3;i>=0;i--){
            int count=0;
            while(!st.empty() && st.top() <= heights[i]){
                st.pop();
                count++;
            }
            if(!st.empty()) count++;
            st.push(heights[i]);
            ans[i]=count;
        }

        return ans;
    }
};