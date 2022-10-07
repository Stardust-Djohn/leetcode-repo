class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        // 动态规划
        //dp[i] 以i结尾的数组的最大结果
        //dp[i] += (nums[i-1] > nums[i]) ? dp[i-1]: 0
        //初始条件：dp[i] = nums[i]
        int n = nums.size();
        int ans = nums[0];
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
        }
        // 动态规划
        for (int i = 1; i < n; i++) {
            dp[i] += (nums[i-1] < nums[i]) ? dp[i-1] : 0;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};