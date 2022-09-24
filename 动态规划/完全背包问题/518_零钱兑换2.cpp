class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //动态规划
        //完全背包问题
        //dp[i] 容量i的金额具有的组合总数
        //递推公式：dp[j] += dp[j - coins[i]]
        //初始条件：dp[0] = 1;
        //递推方向：循环外层为物品，内层为amount:由此可以保证包括所有的组合;如果 循环外层为amount，内层为物品:由此可以保证包括所有的排列
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] += dp[j - coins[i]];
                //cout<<dp[j]<<" ";
            }
        }
        return dp[amount];
        
    }
};