class Solution
{
public:
    string convert(string s, int numRows)
    {
        int n = s.size(), r = numRows;
        // edge case
        if (r == 1 || r > n)
            return s;
        vector<string> mat(r);
        // i表示字符串下标，x表示要填写进的行数；t为判断的标量（数学规律推导）
        for (int i = 0, x = 0, t = r * 2 - 2; i < n; ++i)
        {
            mat[x] += s[i];
            i % t < r - 1 ? ++x : --x;  // 判断模拟z字形的行数变化情况
        }
        string ans;
        for (auto &row : mat)
            ans += row;
        return ans;
    }
};