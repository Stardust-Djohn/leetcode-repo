class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle;
        for (int row = 0; row < numRows; ++row)
        {
            vector<int> r_vec;
            for (int col = 0; col <= row; ++col)
            {
                if (col == 0 || col == row)
                {
                    r_vec.push_back(1);
                }
                else
                {
                    r_vec.push_back(triangle[row - 1][col] + triangle[row - 1][col - 1]);
                }
            }
            triangle.push_back(r_vec);
        }
        return triangle;
    }
};