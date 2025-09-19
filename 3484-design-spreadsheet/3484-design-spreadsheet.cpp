class Spreadsheet {
    vector<vector<int>> grid;
public:
    Spreadsheet(int rows) {
        grid.assign(rows + 1, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int row = stoi(cell.substr(1));
        int col = cell[0] - 'A';

        grid[row][col] = value;
    }
    
    void resetCell(string cell) {
        int row = stoi(cell.substr(1));
        int col = cell[0] - 'A';

        grid[row][col] = 0;
    }
    
    int getValue(string formula) {
        string firstOp = "";
        string secondOp = "";

        int plus =0;
        for(int i=1;i<formula.size();i++){
            
            if(formula[i] == '+'){
                plus=1;
                continue;
            }

            if(plus == 0){
                firstOp += formula[i];
            }else{
                secondOp += formula[i];
            }
        }

        int firstVal=0;
        int secondVal=0;

        if(firstOp[0] >= 'A' && firstOp[0] <='Z'){
            int row = stoi(firstOp.substr(1));
            int col = firstOp[0] - 'A';

            firstVal = grid[row][col];
        }else{
            firstVal = stoi(firstOp);
        }
        if(secondOp[0] >= 'A' && secondOp[0] <='Z'){
            int row = stoi(secondOp.substr(1));
            int col = secondOp[0] - 'A';

            secondVal = grid[row][col];
        }else{
            secondVal = stoi(secondOp);
        }

        return firstVal + secondVal;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */