class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;

        for(char c:s){
            m[c]++;
        }

        multimap<int,char> hm;

        for(auto [key,value]: m){
            hm.insert({value,key});
        }

        string result="";

        for(auto it=hm.rbegin();it!=hm.rend();it++){
            result+=string(it->first,it->second);
        }

        return result;
    }
};