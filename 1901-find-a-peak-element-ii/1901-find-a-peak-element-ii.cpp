class Solution {
public:
    int getMaxRow(vector<vector<int>>& mat, int col) {
        int idx = 0;
        for (int i = 1; i < mat.size(); i++) {
            if (mat[i][col] > mat[idx][col]) {
                idx = i;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int i = getMaxRow(mat, mid);

            int left = (mid - 1 >= 0) ? mat[i][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[i][mid + 1] : -1;

            if (mat[i][mid] > left && mat[i][mid] > right) {
                return {i, mid};
            }
            else if (mat[i][mid] < right) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return {-1, -1};
    }
};
