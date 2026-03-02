class Solution {
public:
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};

    bool check(vector<vector<char>> &board,string &word,int curr,int i,int j){
        if(curr == word.size()) return true;

        if(i>=board.size() || i<0 || j>=board[0].size() || j<0 || board[i][j]=='$') return false;
        
        if(board[i][j]!=word[curr]) return false;

        char temp = board[i][j];
        board[i][j]='$';
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            
            if(check(board,word,curr+1,ni,nj)) return true;
        }
        board[i][j]=temp;



        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        bool found=false;


        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    if(check(board,word,0,i,j)) return true;
                }
            }
        }

        return false;
    }
};