class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int s: nums){
            st.insert(s);
        }

        int longest =0;
        for(int a: st){
            if(st.find(a-1)==st.end()){
                int len = 0;
                while(st.find(a+len)!=st.end()){
                    len+=1;
                }
                longest = max(longest,len);
            }
        }

        return longest;
    }
};