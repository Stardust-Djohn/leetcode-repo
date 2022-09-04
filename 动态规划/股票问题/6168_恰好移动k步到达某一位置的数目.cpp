class Solution {
    const int MOD = 1000000007;

public:
    int numberOfWays(int startPos, int endPos, int K) {
        int d = abs(startPos - endPos);
        if ((d + K) % 2 == 1 || d > K) return 0;
        // 动态规划
        // dp[k][pos]表示从起点出发，用k步到达pos（距离）有几种方法
        vector<vector<long long>> dp;
        dp.resize(K + 1, vector<long long>(K + 1));
        for (int i = 0; i <= K; i++) {
            dp[i][0] = 1;
            // 递推公式：dp[k][pos] = dp[k-1][pos-1] + dp[k-1][pos+1]
            for (int j = 1; j <= i; j++) dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
        }
        return dp[K][(d + K) / 2];
    }
};
// 参考：https://leetcode.cn/circle/discuss/aro81T/
