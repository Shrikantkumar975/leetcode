class Solution {
    vector<int> parent;

    // Standard Find operation with path compression
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    // Standard Union operation
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        parent.resize(n);
        
        // Initialize DSU: each node is its own parent
        for (int i = 0; i < n; i++) parent[i] = i;

        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                // If u and any neighbor v are in the same set, it's not bipartite
                if (find(u) == find(v)) {
                    return false;
                }
                // Union all neighbors of u together
                // They must all belong to the same partition (opposite of u)
                unite(graph[u][0], v);
            }
        }
        return true;
    }
};
