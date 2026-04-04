class Solution {
public:
    string decodeCiphertext(string str, int rows) {
        if(str.size()<=1) return str;

        int col = str.size()/row;

        vector<vector<char>> v(row,vector<char>(col));

        int i=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                v[i][j] = str[i++];
            }
        }

        string ans;

        for(int i=0;i<row;i++){
            int j=0;
            int k=i;

            while(j<col && k<row){
                ans+=v[j][k];
                j+=1;
                k+=1;
            }
        }

        trim(ans);

        return ans;



    }
};