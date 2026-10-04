class Solution {
public:
    bool checkValidString(string s) {
        int starCount = 0;

        int minOpen=0;
        int maxOpen=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                minOpen+=1;
                maxOpen+=1;
            }
            else if(s[i]==')'){
                minOpen-=1;
                maxOpen-=1;
            }
            else {
                minOpen-=1;
                maxOpen+=1;
            }

            minOpen = max(0,minOpen);

            if(maxOpen<0) return false;
        }

        return minOpen == 0;
    }
};