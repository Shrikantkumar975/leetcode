class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int left=0,right=0,i=0;
        string str="";

        while(i<s.size()){

            if (s[i] == ' ') {
                i++;
                left = i;
                right = i;
                continue;
            }

            while(i<s.size() && s[i]!=' '){
                right++;
                i++;
            }

            reverse(s.begin()+left,s.begin()+right);
            str+=s.substr(left,right-left)+" ";
            left=i;
            right=i;
        }

        // left=0;
        // right=s.size()-1;

        // while(s[left]==' '){
        //     left++;
        // }
        // while(s[right]==' '){
        //     right--;
        // }

        return str.substr(0,str.size()-1);
    }
};