class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> dp(len, 1);
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int ans = 0;
        for (auto i : dp)
            ans = (i > ans) ? i : ans;
        return ans;
    }
};