class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //动态规划
        //每日i有2种状态持有/不持有
        //dp[i][j] 每日在某一种状态下所持有的钱数
        //dp[0][0]=0,dp[0][1]=-prices[0];
        //状态转移方程：dp[i][0]:昨天不持有，今天不持有；昨天持有，今天抛售
        //dp[i][1]：昨天持有，今天持有；昨天不持有，今天买入
        //直接使用两重循环即可解决(超时)
//        int dp[100010][2];
//        int len=prices.size();
//        if(len<2) return 0;
//        dp[0][0]=0,dp[0][1]=-prices[0];
//        for(int i=1;i<len;i++){
//            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
//            dp[i][1]=max(dp[i-1][1],-prices[i]);
//
//        }
//
//        return dp[len-1][0];

        //最小前缀和 思想
        int len=prices.size();
        if(len<2) return 0;
        int ans=0,min_p=prices[0];
        for(int i=1;i<len;++i){
            ans=max(ans,prices[i]-min_p);
            min_p=min(prices[i],min_p);
        }
        return ans;


    }
};