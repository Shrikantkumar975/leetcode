class Solution {
public:
    int check(vector<int> &nums,int i,int j){
        int ec=0;
        int oc=0;

        int temp=i;
        set<int> st;
        while(i<=j){
            st.insert(nums[i]);
            i++;
        }

        for(int s: st){
            if(s%2==0) ec++;
            else oc++;
        }

        if(ec==oc) return j-temp+1;
        else return -1;
    }

    int longestBalanced(vector<int>& nums) {
        int s=0;

        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                s = max(s,check(nums,i,j));
            }
        }

        return s;

    }
};