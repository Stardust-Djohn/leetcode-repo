class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int col = 0, row = m-1;
        while(col<n && row>=0){
            if(matrix[row][col] > target) --row;
            else if(matrix[row][col] < target) ++col;
            else return true;
        }
        return false;
    }
};