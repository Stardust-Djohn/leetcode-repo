class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //动态规划完全背包
        //dp[i]:目标数为i时所拥有的排列数
        //递推公式：dp[j] += dp[j - nums[i]]
        //递归顺序：外层为目标数，内层为物品数
        //初始条件：dp[0] = 1;
        int n = nums.size();
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= target; ++j) {
            for (int i = 0; i < n; ++i){
                //有两个数相加超过int的数据，所以需要在if里加上dp[i] < INT_MAX - dp[i - num]
                if (j - nums[i] >= 0 && dp[j] < INT_MAX - dp[j - nums[i]]) 
                    dp[j] += dp[j - nums[i]];
                //cout << dp[j] <<" ";
            }
        }
        return dp[target];
    }
};