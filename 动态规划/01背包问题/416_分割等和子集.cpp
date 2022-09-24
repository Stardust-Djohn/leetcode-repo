class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //判断
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        //动态规划
        //dp[j] 表示：背包总容量是j，最大可以凑成j的子集总和为dp[j]
        //递推公式：dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        //初始条件：dp[0]=0,
        //确定遍历顺序:i=nums.size()在外层
        vector<int> dp(10001, 0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = sum / 2; j >= nums[i]; --j) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return (dp[sum / 2] == sum / 2) ? true : false;
    }
};