class Solution {
public:
    // void fillStack(vector<int>& nums,int start,int end,stack<vector<int>>&st){
    //     int i = start;
    //     int j = start;
    //     int mini = INT_MAX;

    //     while(j<=end){
    //         if(nums[j]==0 && mini != INT_MAX){
    //             st.push({i,j,mini});
    //             mini=INT_MAX;
    //             i=j+1;
    //         }else if(nums[j]==0){
    //             i++;
    //         }else{
    //             mini = min(nums[j],mini);
    //         }
    //         j++;
    //     }

    //     if(i<=end && mini!=INT_MAX){
    //         st.push({i,j-1,mini});
    //     }
    // }

    // int minOperations(vector<int>& nums) {
    //     int ans = 0;

    //     stack<vector<int>> st;

    //     fillStack(nums,0,nums.size()-1,st);

    //     int res =0;

    //     while(!st.empty()){
    //         vector<int> v = st.top();
    //         st.pop();

    //         int a=v[0];
    //         int b=v[1];
    //         int m=v[2];
    //         res++;
    //         for(int k=a;k<=b;k++){
    //             if(nums[k]==m) nums[k]=0;
    //         }
    //         fillStack(nums,a,b,st);
    //     }

    //     return res;

    // }

    int minOperations(vector<int>& nums) {
        stack<int> st;

        int res = 0;

        for(int i=0;i<nums.size();i++){
            int a = nums[i];
            
            if(a==0){
                while(!st.empty()){
                    st.pop();
                }
                continue;
            }
            
            while(!st.empty() && st.top()>a){
                st.pop();
            }

            if(!st.empty() && st.top() == a){
                continue;
            }
            else{
                st.push(a);
                res++;
            }
        }

        return res;
    }


};