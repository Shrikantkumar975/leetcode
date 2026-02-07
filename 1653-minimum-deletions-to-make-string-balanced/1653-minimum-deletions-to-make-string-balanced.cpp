class Solution {
public:
    int minimumDeletions(string s) {
        // stack<char> st;
        int bCount=0;
        int i=0;
        int count=0;
        while(i<s.size()){
            if(s[i]=='b') bCount++;
            else{
                if(bCount>0){
                    bCount--;
                    count++;
                }
            }
            i++;
        }

        return count;
    }
};