class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<int> dx = {0,1,1,1,0,-1,-1,-1};
        vector<int> dy = {1,1,0,-1,-1,-1,0,1};

        vector<vector<int>> copyboard = board;

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int alive=0;
                for(int k=0;k<8;k++){
                    int newi = i +dx[k];
                    int newj = j +dy[k];
                    if(newi>=0 && newi<m && newj>=0 && newj<n && board[newi][newj]==1){
                        alive++;
                    }
                }

                if(board[i][j]==1){
                    if(alive<2 || alive>3) copyboard[i][j]=0;
                    else copyboard[i][j]=1;
                }else{
                    if(alive==3) copyboard[i][j]=1;
                }
            }
        }
        board = copyboard;
    }
};