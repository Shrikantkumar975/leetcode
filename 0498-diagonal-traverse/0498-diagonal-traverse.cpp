class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        if(mat.empty() || mat[0].empty()){
            return {};
        }

        int m= mat.size();
        int n = mat[0].size();

        queue<pair<int,int>> q;
        q.push({0,0});

        vector<int> ans;
        ans.push_back(mat[0][0]);
        mat[0][0] = INT_MIN;

        vector<int> dx = {0,1};
        vector<int> dy = {1,0};
        int count =1;
        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            count++;
            while(size--){
                auto node = q.front();
                q.pop();
                int x = node.first;
                int y = node.second;
                // ans.push(mat[0])
                for(int i=0;i<2;i++){
                    int newX = x+dx[i];
                    int newY = y+dy[i];
                    if(newX<m && newY<n && newX>=0 && newY>=0 && mat[newX][newY]!=INT_MIN){
                        q.push({newX,newY});
                        v.push_back(mat[newX][newY]);
                        mat[newX][newY]=INT_MIN;
                    }
                }
            }

            if(count%2!=0) reverse(v.begin(),v.end());

            for(int i : v){
                ans.push_back(i);
            }

        }

        return ans;

    }
};

// 1
// 2 4
// 