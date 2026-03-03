class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        if(n==1) return s[0];

        while(n>1){
            string temp = s;
            s+="1";
            for(int i=0;i<temp.size();i++){
                temp[i] = temp[i]=='1'?'0':'1';
            }
            int i=0;
            int j=temp.size()-1;

            while(i<j){
                swap(temp[i],temp[j]);
                i++;
                j--;
            }
            s+=temp;
            n--;
        }

        return s[k-1];
    }
};