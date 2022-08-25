class Solution {
public:
    int climbStairs(int n) {
        //动态规划
        if (n <= 2) return n;
        int dp[2];
        dp[0] = 1;
        dp[1] = 2;
        int num;
        for(int i = 3; i <= n; ++i){
            num = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = num;
        }
        return num;
    }
};