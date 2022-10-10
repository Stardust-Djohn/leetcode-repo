class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //动态规划
        //dp[i][j]:text1中i结尾和text2中j结尾的最长公共子序列长度
        //递推公式：
        /*
        if text1[i-1] == text2[j-1]: dp[i][j] = dp[i-1][j-1] + 1]
        if text1[i-1] != text2[j-1]: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        */
        //初始条件：dp[0][j] = dp[i][0] = 0;
        //遍历方向：两层循环
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, 0));
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (text1[i-1] == text2[j-1]) 
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};