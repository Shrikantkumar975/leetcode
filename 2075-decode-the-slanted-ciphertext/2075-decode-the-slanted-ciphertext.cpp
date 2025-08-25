class Solution {
public:
    string decodeCiphertext(string str, int rows) {
        if(str.size()<=1) return str;
        int col = str.size()/rows;

        int i=0;
        vector<vector<char>> mat(rows,vector<char>(col));
        for(int j=0;j<rows;j++){
            for(int k=0;k<col;k++){
                char ch = str[i++];
                mat[j][k] = ch;
            }
        }

        string ans;
        queue<pair<int,int>> q;
        q.push({0,0});
        // ❌ removed: ans.push_back(mat[0][0]);

        int count = 0;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int x = node.first;
            int y = node.second;

            int j=x;
            int k=y;

            while(j<rows && k<col){
                ans+=mat[j][k];   // ✅ directly add current cell
                j++;
                k++;
            }
            
            if(y+1<col){
                q.push({x,y+1});
                // ❌ removed: ans+=mat[x][y+1];
            }
        }

        // trim trailing spaces
        i=ans.size()-1;
        while(i>=0){
            if(ans[i] == ' ') ans.pop_back();
            else break;
            i--;
        }

        return ans;
    }
};
