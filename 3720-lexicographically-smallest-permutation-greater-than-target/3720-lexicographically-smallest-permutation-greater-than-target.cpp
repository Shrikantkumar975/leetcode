// class Solution {
// public:
//     string lexGreaterPermutation(string s, string target) {
//         vector<int> v(26,0);

//         for(char ch: s){
//             v[ch-'a']++;
//         }

//         int getBigger = 0;

//         string ans="";

//         for(int i=0;i<s.size();i++){
//             char curr = target[i];
//             if(v[curr-'a']!=0){
//                 ans.push_back(curr);
//                 v[curr-'a']--;
//             }else{
//                 for(int j=(curr-'a');j<26;j++){
//                     if(v[j]>0){
//                         ans.push_back(j+'a');
//                         v[j]--;
//                         getBigger=1;
//                         break;
//                     }
//                 }
//             }
//             if(getBigger) break;
//         }

//         if(getBigger){
//             for(int i=0;i<26;i++){
//                 while(v[i]>0){
//                     ans+=i+'a';
//                     v[i]--;
//                 }
//             }
//         }else{
//             return "";
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string result = "";

    bool solve(string& curr, vector<int>& count, string& target, int i, bool greater) {
        if(i == target.length()) {
            if(greater) {
                result = curr;
                return true;
            }
            return false;
        }

        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(count[ch-'a'] == 0)
                continue;
            
            if(greater == false && ch < target[i])
                continue;
            

            curr.push_back(ch);
            count[ch-'a']--;

            bool isGreater = greater || ch > target[i];

            if(solve(curr, count, target, i+1, isGreater)) {
                return true;
            }

            curr.pop_back();
            count[ch-'a']++;
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);

        for(char &ch : s)
            count[ch-'a']++;
        
        string curr;

        solve(curr, count, target, 0, false);

        return result;
    }
};
