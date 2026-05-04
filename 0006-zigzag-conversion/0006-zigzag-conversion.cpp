class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> arr(numRows,"");

        int i=0;

        while(i<s.size()){
            for(int j=0;j<numRows;j++){
                if(i<s.size()){
                    arr[j]+=s[i];
                    i++;
                }
            }

            for(int j=numRows-2;j>0;j--){
                if(i<s.size()){
                    arr[j]+=s[i];
                    i++;
                }
            }
        }

        string ans="";
        for(int i=0;i<arr.size();i++){
            ans+=arr[i];
        }

        return ans;
    }
};