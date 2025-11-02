class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<int> &d,int &ans,int i,int j){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return;
        if(board[i][j]=='B') return;

        if(board[i][j]=='p'){
            ans++;
            return;
        }

        dfs(board,d,ans,i+d[0],j+d[1]);
    }

    int numRookCaptures(vector<vector<char>>& board) {
        vector<vector<int>> d = {{0,1},{0,-1},{1,0},{-1,0}};
        int ans=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='R'){
                    dfs(board,d[0],ans,i,j+1);
                    dfs(board,d[1],ans,i,j-1);
                    dfs(board,d[2],ans,i+1,j);
                    dfs(board,d[3],ans,i-1,j);
                }
            }
        }

        return ans;
    }
};