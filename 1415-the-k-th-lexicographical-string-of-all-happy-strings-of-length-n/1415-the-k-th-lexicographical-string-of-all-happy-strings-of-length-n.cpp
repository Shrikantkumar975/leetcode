class Solution {
public:
    void solve(vector<string> &v,int ch,string &str,int n){
        if(str.size()>n) return;

        if(str.size()==n){
            v.push_back(str);
            return;
        }


        for(int i=0;i<3;i++){
            if(i==ch) continue;
            str.push_back(char(97+i));
            solve(v,i,str,n);
            str.pop_back();
        }
        
    }

    string getHappyString(int n, int k) {
        vector<string> v;
        string str="";

        for(int i=0;i<3;i++){
            str.push_back(char(97+i));
            solve(v,i,str,n);
            str.pop_back();
        }

        sort(v.begin(),v.end());

        if(k>v.size()) return ""; 
        return v[k-1];
    }
};