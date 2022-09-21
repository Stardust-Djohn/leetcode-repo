class Solution {
public:
    void count(int& zeroNum, int& oneNum, string& str) {
        for (auto &c : str){
            if (c == '0') zeroNum++;
            else oneNum++;
        }
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        //动态规划
        //01背包问题，m、n是两个不同维度的背包容量
        //dp[i][j]:前一个strs里的字符串推导出来，strs里的字符串有zeroNum个0，oneNum个1时的最大子集
        //递推公式：dp[i - zeroNum][j - oneNum] + 1
        //初始条件dp[0][0]=0
        //递推方向：同滚动数组，仅只是包含了ij两维

        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        int oneNum = 0, zeroNum = 0;
        for (auto str : strs) {
            oneNum = 0, zeroNum = 0;
            count(zeroNum, oneNum, str);
            for (int i = m; i >= zeroNum; --i){
                for (int j = n; j >= oneNum; --j){
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};