class Solution {
public:
    int numTrees(int n) {
        //动态规划
        //dp[n]:n个节点能形成的BST数量
        //递推关系：dp[i] += dp[以j为头结点左子树节点数量] * dp[以j为头结点右子树节点数量]
        //dp[0]=0,dp[1]=1,dp[2]=2;
        //递推方向：依靠i之前的状态
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= i; ++j){
                dp[i] += dp[j - 1] * dp[i - j];
                //cout<<dp[i]<<"+="<<dp[j]<<"*"<<dp[i-j];
            }
        }
        return dp[n];
    }
};