class Solution {
public:
    void back(vector<vector<char>>& board,string word,int i,int j,int k,bool &ans){
        if(ans) return;

        if(k==word.size()){
            ans=true;
            return;
        }

        if(i>=board.size() || i<0 || j>=board[0].size() || j<0 || board[i][j]!=word[k]){
            return;
        }

        char temp = board[i][j];
        board[i][j]='0';

        back(board,word,i+1,j,k+1,ans);
        back(board,word,i-1,j,k+1,ans);
        back(board,word,i,j+1,k+1,ans);
        back(board,word,i,j-1,k+1,ans);

        board[i][j] = temp;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        bool ans =0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                back(board,word,i,j,0,ans);
                if(ans) break;
            }
        }

        return ans;
    }
};