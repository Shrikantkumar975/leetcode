class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mini = INT_MAX;

        for(string &s : strs){
            if(s.length() < mini) mini =s.length();
        }

        int i;
        for(i=0;i<mini;i++){
            int got = false;
            for(int j=0;j<strs.size()-1;j++){
                if(strs[j][i] != strs[j+1][i]){
                    got=true;
                    break;
                }
            }
            if(got) break;
        }

        return strs[0].substr(0,i);
    }
};