class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle(2);  // 要压缩空间
        for(int row = 0; row <= rowIndex; ++row){
            vector<int> r_vec;
            for(int col = 0; col <= row; ++col){               
                if(col == 0 || col == row){
                    r_vec.push_back(1);
                }
                else{
                    r_vec.push_back(triangle[0][col] + triangle[0][col-1]);
                }
            }
            triangle[1] = triangle[0];
            triangle[0] = r_vec;
        }
        //就在上一题的基础上，只返回特定的行
        return triangle[0];
    }
};