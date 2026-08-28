class Solution {
public:
    char midChar;
    string ans="";
    int half;


    bool generate(string curr, string &target, vector<int> &v, int i, bool greater){
        if(i==half){
            string rev = curr;
            reverse(rev.begin(),rev.end());

            if(target.size()%2!=0){
                curr+=midChar;
            }

            curr+=rev;

            if(curr > target){
                ans = curr;
                return true;
            }

            return false;
        }

        for(char ch='a';ch<='z';ch++){
            if(v[ch-'a']==0){
                continue;
            }

            if(greater == false && ch < target[i]) continue;

            curr.push_back(ch);
            v[ch-'a']--;

            bool isGreater = greater || ch>target[i];
            if(generate(curr,target,v,i+1,isGreater)) return true;

            curr.pop_back();
            v[ch-'a']++;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        vector<int> v(26,0);

        for(char c: s){
            v[c-'a']++;
        }

        int oddCount=0;

        for(int i=0;i<26;i++){
            if(v[i]%2!=0){
                oddCount++;
                midChar=i+'a';
                v[i]--;
            }
            v[i]/=2;
        }

        if(oddCount>1) return "";


        half = target.size()/2;
        string curr;

        generate(curr,target,v,0,false);
        
        return ans;
    }
};