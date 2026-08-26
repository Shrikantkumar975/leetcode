class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int curr1=0;
        string ans="99";

        int i=0;
        int j=0;

        while(j<s.size()){
            if(s[j]=='1') curr1++;

            while(curr1>k || (i <= j && s[i] == '0')){
                if(s[i]=='1'){
                    curr1--;
                }
                i++;
            }

            if(curr1==k){
                string curr = s.substr(i,j-i+1);

                if(ans=="99") ans = curr;
                else{
                    if(curr.size()<ans.size()) ans=curr;
                    else if(curr.size() == ans.size()) ans = min(curr,ans);
                }
            }

            j++;
        }

        if(ans == "99") return "";
        return ans;
    }
};