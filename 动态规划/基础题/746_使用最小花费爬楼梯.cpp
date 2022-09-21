class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //动态规划
        //dp：当前i花费的最小体力
        //2.当前i台阶比较min(dp[i-2], dp[i-1])+cost[i]
        //3.初始条件：起始台阶的体力
        //4.方向：由低往高，取min
        //5.举例：得出最后一步后还需比较min
        int dp[2];
        dp[0] = cost[0];
        dp[1] = cost[1];
        int ct;
        for(int i = 2; i < cost.size(); ++i){
            ct = min(dp[1], dp[0]) + cost[i];
            dp[0] = dp[1];
            dp[1] = ct;
        }
        return min(dp[0], dp[1]);
    }
};