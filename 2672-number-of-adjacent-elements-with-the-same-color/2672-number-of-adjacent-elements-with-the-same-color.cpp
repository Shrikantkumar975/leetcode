class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {

        vector<int> color(n,0);
        vector<int> ans;
        int total = 0;

        for(auto &q : queries){

            int idx = q[0];
            int val = q[1];

            if(color[idx] != 0){

                if(idx-1>=0 && color[idx]==color[idx-1])
                    total--;

                if(idx+1<n && color[idx]==color[idx+1])
                    total--;
            }

            color[idx] = val;

            if(idx-1>=0 && color[idx]==color[idx-1])
                total++;

            if(idx+1<n && color[idx]==color[idx+1])
                total++;

            ans.push_back(total);
        }

        return ans;
    }
};