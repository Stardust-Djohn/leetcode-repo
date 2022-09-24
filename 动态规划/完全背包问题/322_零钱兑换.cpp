class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //动态规划完全背包
        //dp[i]:amount为i时的最少个数
        //递推关系：dp[j] = min(dp[j], dp[j - coins[i]] + 1)
        //初始条件：dp[0] = 0,其余应该设置为最大整数;
        //递推方向：外层为物品循环，内层为金额（容量）循环
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                if (dp[j - coins[i]] != INT_MAX) { // 如果dp[j - coins[i]]是初始值则跳过
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
                //cout<<dp[j]<<" ";
            }
        }
        return (dp[amount] != INT_MAX) ? dp[amount] : -1;
    }
};