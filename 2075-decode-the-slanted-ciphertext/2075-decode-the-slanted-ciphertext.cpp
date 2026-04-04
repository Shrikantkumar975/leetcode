class Solution {
public:
    string decodeCiphertext(string str, int row) {
        if(str.size()<=1 || row<=1) return str;

        int col = str.size()/row;

        vector<vector<char>> v(row,vector<char>(col));

        int k=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                char ch = str[k];
                v[i][j]=ch;
                k++;
            }
        }
        string ans;

        for(int i=0;i<col;i++){
            int j=0;
            int k=i;

            while(j<row && k<col){
                ans+=v[j][k];
                j+=1;
                k+=1;
            }
        }


        int i=0;
        int j=ans.size()-1;

        while(j >= 0 && ans[j] == ' ') j--;

        return ans.substr(i,j-i+1);

        return ans;

    }
};