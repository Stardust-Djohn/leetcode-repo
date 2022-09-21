class Solution {
public:
    int uniquePaths(int m, int n) {
        //动态规划
        //dp[i][j]:当前二维位置的路径方法
        //递推：当前格子是其左/上方向的加和
        //起始条件：dp[0][j],dp[i][0]均为1
        //递推方向：i,j只能增加
        int dp[m][n];
        for (int i = 0; i < m; ++i){
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j){
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; ++i){
            for (int j = 1; j < n; ++j){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                //cout<<dp[i][j]<<" ";
            }
        }
        return dp[m-1][n-1];
    }
};