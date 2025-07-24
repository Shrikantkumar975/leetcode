class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> left(prices.size(),0);
        vector<int> right(prices.size(),0);
        int n = prices.size();
        left[0] = prices[0];
        right[n-1] = prices[n-1];
        for(int i=1;i<prices.size();i++){
            left[i] = min(left[i-1],prices[i]);
            right[n-i-1] = max(prices[n-i-1],right[n-1]);
        }

        int m =0;
        for(int i=0;i<n;i++){
            m = max(m,right[i]-left[i]);
        }

        return m;
    }
};