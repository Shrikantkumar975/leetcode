class Solution {
public:
    vector<int> findNextMin(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n, n);
        stack<int> st ;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }

        return nse;
    }

    vector<int> findPrevMin(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse(n, -1);
        stack<int> st ;
        
        for (int i =0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }

        return pse;
    }

    int maximumScore(vector<int>& nums, int k) {
        vector<int> left;
        vector<int> right;

        right = findNextMin(nums);
        left = findPrevMin(nums);

        int ans=0;

        for(int i=0;i<nums.size();i++){
            if(k>left[i] && k<right[i])
            ans = max(ans,nums[i]*((right[i]-1)-(left[i]+1) + 1));
        }

        return ans;
    }
};