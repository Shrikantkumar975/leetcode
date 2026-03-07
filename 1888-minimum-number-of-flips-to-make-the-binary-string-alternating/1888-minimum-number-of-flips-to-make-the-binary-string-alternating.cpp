class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        s+=s;
        char curr ='1';
        string s1 = "";
        string s2 = "";

        for(int i=0;i<2*n;i++){
            s1.push_back(curr);
            curr=(curr == '1') ? '0' : '1';;
        }

        curr='0';
        for(int i=0;i<2*n;i++){
            s2.push_back(curr);
            curr=(curr == '1') ? '0' : '1';;
        }

        int c1 = 0;
        int c2 = 0;

        for(int i=0;i<n;i++){
            if(s1[i]!=s[i]) c1++;
        }

        for(int i=0;i<n;i++){
            if(s2[i]!=s[i]) c2++;
        }

        int ans = min(c1,c2);

        int i=n;

        while(i<2*n){
            if(s[i-n] != s1[i-n]) c1--;
            if(s[i] != s1[i]) c1++;

            if(s[i-n] != s2[i-n]) c2--;
            if(s[i] != s2[i]) c2++;

            ans = min(ans,min(c1,c2));
            i++;
        }

        return ans;
    }
};