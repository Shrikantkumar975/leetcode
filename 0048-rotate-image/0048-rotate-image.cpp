class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // we do the transpose
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // then we reverse 
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
};