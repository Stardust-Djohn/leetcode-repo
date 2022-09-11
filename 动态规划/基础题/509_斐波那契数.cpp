class Solution {
public:
    int fib(int n) {
        //动态规划方法
        if (n <= 1) return n;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        int sum;
        for (int i = 2; i <= n; ++i) {
            sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};