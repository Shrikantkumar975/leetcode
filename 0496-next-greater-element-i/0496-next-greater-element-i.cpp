class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> v(nums2.size());

        v[nums2.size()-1] = -1;
        st.push(nums2[nums2.size()-1]);

        for(int i=nums2.size()-2;i>=0;i--){

            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }

            if(st.empty()){
                v[i] = -1;
                st.push(nums2[i]);
            }else{
                v[i] = st.top();
                st.push(nums2[i]);
            }

        }

        unordered_map<int,int> m;

        for(int i=0;i<v.size();i++){
            m[nums2[i]] = v[i];
        }

        vector<int> s;
        for(int i=0;i<nums1.size();i++){
            s.push_back(m[nums1[i]]);
        }

        return s;
    }
};