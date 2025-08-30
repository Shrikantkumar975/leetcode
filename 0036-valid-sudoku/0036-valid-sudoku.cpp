class Solution {
public:
    // bool check(int sr,int er,int sc,int ec,vector<vector<char>> &board){
    //     set<char> s;

    //     for(int i=sr;i<=er;i++){
    //         for(int j=sc;j<=ec;j++){
    //             if(board[i][j] == '.') continue;

    //             if(s.find(board[i][j]) != s.end()){
    //                 return false;
    //             }

    //             s.insert(board[i][j]);
    //         }
    //     }

    //     return true;
    // }

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> s;

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                if (board[row][col] == '.')
                    continue;

                string s1 = string(1, board[row][col]) + "Row" + to_string(row);
                string s2 = string(1, board[row][col]) + "Col" + to_string(col);
                string s3 = string(1, board[row][col]) + "Box" +
                            to_string(row / 3) + to_string(col / 3);

                if (s.count(s1) || s.count(s2) || s.count(s3))
                    return false;

                s.insert(s1);
                s.insert(s2);
                s.insert(s3);
            }
        }

        // for(int row = 0;row<9;row++){
        //     set<char> s;
        //     for(int col = 0;col<9;col++){
        //         if(board[row][col] == '.') continue;

        //         if(s.find(board[row][col]) != s.end()) return false;

        //         s.insert(board[row][col]);
        //     }
        // }

        // for(int col = 0;col<9;col++){
        //     set<char> s;
        //     for(int row = 0;row<9;row++){
        //         if(board[row][col] == '.') continue;

        //         if(s.find(board[row][col]) != s.end()) return false;

        //         s.insert(board[row][col]);
        //     }
        // }

        // for(int row=0;row<9;row+=3){
        //     int re = row+2;
        //     for(int col=0;col<9;col+=3){
        //         int ce = col+2;

        //         if(!check(row,re,col,ce,board)) return false;
        //     }
        // }

        return true;
    }
};