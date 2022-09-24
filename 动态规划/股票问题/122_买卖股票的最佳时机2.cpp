class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //动态规划；
        //dp[i][0] 表示第i天持有股票所得现金。dp[i][1] 表示第i天不持有股票所得最多现金
        //递推公式：dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]); dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        //初始条件：dp[0][0] -= prices[0],dp[0][1] = 0;
        ///滚动数组
        int len = prices.size();
        vector<vector<int>> dp(2, vector<int> (2, 0));
        dp[0][0] -= prices[0];
        for (int i = 1; i < len; ++i) {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] - prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i]);
            //cout << dp[i][0]<<" "<<dp[i][1]<<" ";
        }
        return dp[(len - 1) % 2][1];
    }
};