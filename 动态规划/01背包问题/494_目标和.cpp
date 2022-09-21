class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //动态规划
        //假设选择+的数的和x，选择-的数的和为-（sum-x）,有x-（sum-x）=target,有x=(sum+target)/2
        //原题目转化为:在nums中选择几个数使其和为x的组合数
        //01背包,组合类问题
        //dp[i]:填满x（包括x）这么大容积的包，有dp[j]种方法
        //推导公式:dp[j]=dp[j-nums[i]]，在选择nums[i]的情况下
        //起始条件：dp[0]=1
        //递推方向：滚动数组
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < abs(target)) return 0;
        if ((sum + target) % 2 == 1) return 0;
        int n = nums.size(), x = (sum + target) / 2;
        vector<int> dp(x + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = x; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
                //cout<<dp[j]<<endl;
            }
        }
        return dp[x];

    }
};