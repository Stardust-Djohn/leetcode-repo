class Solution {
public:
    int integerBreak(int n) {
        //动态规划
        //dp[i]：分拆数字i，可以得到的最大乘积为dp[i]
        //递推公式：dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
        //j * (i - j) 是单纯的把整数拆分为两个数相乘，而j * dp[i - j]是拆分成两个以及两个以上的个数相乘。
        //边界条件：只初始化dp[2] = 1
        //遍历顺序：dp[i] 是依靠 dp[i - j]的状态，所以遍历i一定是从前向后遍历
        vector<int> dp(n+1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; ++i){
            for (int j = 1; j < i-1; ++j){
                dp[i] = max({dp[i], (i-j)*j, dp[i-j]*j});
                //cout<<dp[i]<<" "<<(i-j)*j<<" "<<dp[i-j]*j<<endl;
            }
        }
        return dp[n];
    }
};