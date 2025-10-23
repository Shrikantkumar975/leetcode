class Solution {
public:
    string reduceNumber(string s){
        string n;

        for(int i=0;i<s.size()-1;i++){
            int rem = (s[i]-'0' + s[i+1]-'0')%10;
            n.push_back(rem+'0');
        }

        return n;
    }

    bool hasSameDigits(string s) {
        while(s.size()>2){
            s=reduceNumber(s);
        }

        if(s[0] == s[1]) return true;
        return false;
    }
};