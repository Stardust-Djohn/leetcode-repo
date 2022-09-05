class Solution {
public:
    int nthUglyNumber(int n) {
        // 动态规划
        // dp[i]第i个丑数的大小
        // 递推公式dp[i] = min(dp[p2]*2,dp[p3]*3,dp[p5]*5)
        // 初始条件：dp[1]==1
        vector<int> dp(n+1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1; // 表示是由第p个数乘以2/3/5得到的
        for (int i = 2; i <= n; ++i) {
            int num1 = dp[p2]*2, num2 = dp[p3]*3, num3 = dp[p5]*5;
            dp[i] = min({num1, num2, num3});
            if (num1 == dp[i]) p2++;
            if (num2 == dp[i]) p3++;
            if (num3 == dp[i]) p5++;
        }
        return dp[n];
    }
};