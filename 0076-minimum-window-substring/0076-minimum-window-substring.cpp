class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp;

        for(char ch: t){
            mpp[ch]++;
        }
        int count=t.size();

        int i=0;
        int j=0;

        int ans=INT_MAX;
        int start_i=0;

        while(j<s.size()){
            if(mpp[s[j]]>0){
                count--;
                // j++;
            }
            mpp[s[j]]--;
            while(count==0){
                int currSize = j-i+1;

                if(ans>currSize){
                    ans=currSize;
                    start_i=i;
                }

                mpp[s[i]]++;

                if(mpp[s[i]]>0){
                    count++;
                }

                i++;
            }
            j++;
        }

        return ans==INT_MAX?"":s.substr(start_i,ans);
    }
};