class Solution {
public:
    int numSquares(int n) {
        //动态规划完全背包问题
        //dp[i]:和为i的完全平方数的最小数量
        //递推公式：dp[j] = min(dp[j], dp[j - nums[i]] + 1)
        //起始条件：dp[1]=1;dp[0]=1;
        //推导方向：外层循环为物品，内层为n，可以互换，均为正向
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 1, dp[0] = 0;
        for (int j = 0; j <= n; ++j) {
            for (int i = 1; i * i <= j; ++i) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
                //cout << dp[j] << " ";
            }
        }
        return dp[n];
    }
};