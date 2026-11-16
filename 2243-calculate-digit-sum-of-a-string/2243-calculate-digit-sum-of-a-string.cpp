class Solution {
public:
    string digitSum(string s, int k) {
        string s1;
        while(s.size()>k){
            s1="";
            int i=0;
            while(i<s.size()){
                int sum=0;
                int count=0;
                while(i<s.size() && count<k){
                    sum+=s[i]-'0';
                    count++;
                    i++;
                }
                s1+=to_string(sum);
            }
            s=s1;
        }

        return s;
    }
};
