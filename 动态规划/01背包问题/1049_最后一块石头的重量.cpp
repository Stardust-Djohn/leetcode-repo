class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //动态规划
        //dp[j]:背包问题中容量j的背包可承载的最大的石头重量
        //递推公式：dp[j]=max(dp[j], dp[j-stones[i]]+stones[i])
        //初始条件：dp[0]=0;
        //遍历方向：使用一维dp数组，物品遍历的for循环放在外层，遍历背包的for循环放在内层，且内层for循环倒序遍历
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<int> dp(target+1, 0);
        for (int i = 0; i < stones.size(); ++i){
            for (int j = target; j >= stones[i]; --j){
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
                //cout<<dp[i]<<" ";
            }
        }
        return sum - dp[target] * 2;

    }
};