class Solution {
public:
    int characterReplacement(string s, int k) {
        
        // int maxLen = 0;

        // for(int i=0;i<s.size();i++){
        //     vector<int> hash(26,0);
        //     int maxF=0;

        //     for(int j=i;j<s.size();j++){
        //         hash[s[j]-'A']++;
        //         maxF = max(maxF,hash[s[j]-'A']);
        //         int changes = (j-i+1)-maxF;
                
        //         if(changes<=k){
        //             maxLen = max(maxLen,j-i+1);
        //         }else{
        //             break;
        //         }
        //     }
        // }

        // return maxLen;  T.C -> O(n^2)

        int r=0,l=0,maxLen=0,maxf=0;
        vector<int> hash(26,0);

        while(r<s.size()){
            hash[s[r]-'A']++;
            maxf = max(maxf,hash[s[r]-'A']);

            // while(r-l+1-maxf > k){
            //     hash[s[l]-'A']--;
            //     maxf=0;
            //     for(int i=0;i<26;i++){
            //         maxf = max(maxf,hash[i]);
            //     }
            //     l+=1;
            // }
            if(r-l+1-maxf > k){
                hash[s[l]-'A']--;
                // maxf=0;
                // for(int i=0;i<26;i++){
                //     maxf = max(maxf,hash[i]);
                // }
                l+=1;
            }

            if(r-l+1-maxf <= k){
                maxLen = max(maxLen,r-l+1);
            }
            r++;
        }

        return maxLen;
    }
};