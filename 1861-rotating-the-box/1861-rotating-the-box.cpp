class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();



        for(int k=0;k<n;k++){
            int i=m-1;
            int j=m-1;

            while(j>=-1){
                if(j==-1 || boxGrid[k][j]=='*'){
                    while(i>j){
                        boxGrid[k][i]='.';
                        i--;
                    }
                    j--;
                    i=j;
                }else if(boxGrid[k][j]=='#'){
                    boxGrid[k][i]='#';
                    i--;
                    j--;
                }else{
                    j--;
                }
            }


        }

        vector<vector<char>> newBox(m,vector<char>(n,'.'));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                newBox[j][i] = boxGrid[i][j];
            }
        }

        for(int i=0;i<m;i++){
            reverse(newBox[i].begin(),newBox[i].end());
        }

        return newBox;

    }
};

// 46:30 min