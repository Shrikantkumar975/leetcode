class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>> newBox(m,vector<char>(n,'0'));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                newBox[j][i] = boxGrid[i][j];
            }
        }

        for(int i=0;i<m;i++){
            reverse(newBox[i].begin(),newBox[i].end());
        }

        for(int i=0;i<n;i++){
            int count=0;
            int curr = -1;
            stack<pair<int,int>> st;
            // st.push(-1);
            for(int j=0;j<m;j++){
                if(boxGrid[i][j]=='*'){
                    st.push({curr,count});
                    curr=j;
                    count=0;
                }
                else if(boxGrid[i][j] == '#') count++;
            }

            st.push({curr,count});
            
            int col = n-i-1;
            int row = m-1;

            while(!st.empty()){
                auto [till,cnt] = st.top();
                st.pop();

                while(row > -1){
                    if(row==till){
                        newBox[row][col]='*';
                        row--;
                    }
                    if(cnt==0){
                        while(row>till && row>=-1){
                            newBox[row][col]='.';
                            row--;
                        }
                        if(row!=-1)
                            newBox[row][col]='*';
                        row=till-1;
                        break;
                    }
                    newBox[row--][col] = '#';
                    cnt--;
                }
            }
        }

        return newBox;

    }
};