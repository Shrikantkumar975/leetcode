class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> v(256,0);

        for(char c: t){
            v[c]++;
        }

        int i=0;
        int j=0,n=s.size(),m=t.size();
        int start = 0;
        int count=0;
        int len = 1e9;

        while(j<n){
            if(v[s[j]] > 0){
                count++;
            }
            v[s[j]]--;

            while(count == m){
                if(len > j-i+1){
                    len = j-i+1;
                    start =i;
                }

                v[s[i]]++;
                if(v[s[i]]>0) count--;
                i++;
            }
            j++;
        }

        return len==1e9 ? "" : s.substr(start,len);
    }
};