class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        // 哈希表方法
        // 额外开辟行、列哈希表
        int n_row = mat.size(), n_col = mat[0].size();
        int ans = 0;
        vector<int> col(n_col), row(n_row);
        for (int i = 0; i < n_row; ++i) {
            for (int j = 0; j < n_col; ++j) {
                if (mat[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for (int i = 0; i < n_row; ++i ){
            for (int j = 0; j < n_col; ++j) {
                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1) ans++;
            }
        }
        return ans;
    }
};