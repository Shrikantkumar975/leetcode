class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = *min_element(nums1.begin(),nums1.end());

        int parity = 0;

        if(mini%2==1) parity=1;

        for(int i=0;i<nums1.size();i++){
            if(parity == 0 && nums1[i]%2==1) return false;
        }
        return true;
    }
};