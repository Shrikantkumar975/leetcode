class Solution {
public:
    // using T = tuple<int,int,int>;
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();

        vector<vector<int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back(
                {positions[i], healths[i], directions[i] == 'L' ? -1 : 1, i});
        }

        sort(v.begin(), v.end());

        stack<vector<int>> st;

        for (int i = 0; i < n; i++) {
            if (v[i][2] == -1) {
                while (!st.empty() && st.top()[2] == 1) {
                    vector<int> curr = st.top();
                    st.pop();

                    if (curr[1] == v[i][1]){
                        v[i][2]=0;
                        break;
                    }
                    else if (curr[1] > v[i][1]) {
                        st.push({curr[0], curr[1] - 1, curr[2], curr[3]});
                        v[i][2] = 0;
                        break;
                    } else {
                        v[i][1] -= 1;
                    }
                }
                if (v[i][2] != 0)
                    st.push(v[i]);
            } else {
                st.push(v[i]);
            }
        }

        if(st.empty()) return {};

        v.clear();

        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }

        auto fun = [](const vector<int>& a, const vector<int>& b) -> bool {
            if (a[3] < b[3]) {
                return true;
            }
            return false;
        };
        sort(v.begin(), v.end(), fun);

        vector<int> ans;

        for(int i=0;i<v.size();i++){
            ans.push_back(v[i][1]);
        }

        return ans;
    }
};