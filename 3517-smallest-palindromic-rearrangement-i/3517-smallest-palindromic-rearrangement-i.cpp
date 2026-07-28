class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> mpp;

        char odd=' ';

        for(char c: s){
            mpp[c]++;
        }

        string str="";

        for(auto p: mpp){
            if(p.second%2!=0) odd=p.first;
            int curr = p.second/2;

            while(curr--){
                str+=p.first;
            }
        }

        string temp = str;
        reverse(temp.begin(),temp.end());

        if(odd!=' ') str+=odd;

        return str+temp;
    }
};