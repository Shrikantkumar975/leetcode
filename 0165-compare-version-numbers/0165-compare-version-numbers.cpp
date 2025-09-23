class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;
        string s="";
        for(char c: version1){
            if(c =='.'){
                v1.push_back(stoi(s));
                s="";
            }else s+=c;
        }
        v1.push_back(stoi(s));
        s="";

        for(char c: version2){
            if(c =='.'){
                v2.push_back(stoi(s));
                s="";
            }else s+=c;
        }
        v2.push_back(stoi(s));

        int n = max(v1.size(), v2.size());
        for (int i=0; i<n; i++) {
            int a = (i < v1.size() ? v1[i] : 0);
            int b = (i < v2.size() ? v2[i] : 0);
            if (a > b) return 1;
            if (a < b) return -1;
        }
        return 0;
    }
};