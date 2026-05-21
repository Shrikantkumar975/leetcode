class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int> st;
        stack<int> s;

        for(int i=0;i<arr1.size();i++){
            while(arr1[i]){
                s.push(arr1[i]%10);
                arr1[i]/=10;
            }

            int newNum=0;
            while(!s.empty()){
                newNum = newNum*10+s.top();
                st.insert(newNum);
                s.pop();
            }
        }

        int ans=0;
        for(int i=0;i<arr2.size();i++){
            while(arr2[i]){
                s.push(arr2[i]%10);
                arr2[i]/=10;
            }

            int newNum=0;
            int count=0;
            while(!s.empty()){
                newNum = newNum*10+s.top();
                count++;
                if(st.find(newNum)==st.end()) break; 
                s.pop();
                ans=max(ans,count);
            }
            while(!s.empty()) s.pop();
        }

        return ans;
    }
};