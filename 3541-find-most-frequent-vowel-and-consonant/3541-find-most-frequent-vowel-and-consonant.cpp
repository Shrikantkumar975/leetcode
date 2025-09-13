class Solution {
public:
    int maxFreqSum(string s) {
        int vow = 0;
        int con = 0;

        map<char,int> vo;
        map<char,int> co;

        string s1 = "aeiouAEIOU";

        for(auto &ch : s){
            if(s1.find(ch) != string::npos){
                vo[ch]++;
                vow = max(vo[ch],vow);
            }else{
                co[ch]++;
                con = max(con,co[ch]);
            }
        }

        return con+vow;

    }
};