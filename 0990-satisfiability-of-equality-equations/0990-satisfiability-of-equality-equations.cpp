class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
            rank[i] = i;
        }

        for (string& eq : equations) {
            int u = eq[0] - 'a';
            int v = eq[3] - 'a';
            char op = eq[1];

            if (op == '=') {
                Union(u, v);
            }
        }
        for (string& eq : equations) {
            int u = eq[0] - 'a';
            int v = eq[3] - 'a';
            char op = eq[1];

            if (op == '!') {
                int parent_u = find(u);
                int parent_v = find(v);

                if (parent_u == parent_v) {
                    return false;
                }
            }
        }
        return true;
    }
};