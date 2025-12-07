class Solution {
public:
    int countOdds(int low, int high){
        int ans = high-low + (high%2==0?0:1) +(low%2==0?0:1);

        return ans/2;
    }
};


