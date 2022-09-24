class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //动态规划
        //dp[i][j]nums1下标i-1和nums2下标j-1结尾组成的最长子数组长度
        //递推公式：if(nums1[i]==num2[j]) dp[i][j]=dp[i-1][j-1]+1;
        //初始条件：dp[i][j]=0;
        //递推方向：两层循环
        //滚动数组
        int n1 = nums1.size(), n2 = nums2.size(), result = 0;
        vector<int> dp(n2 + 1, 0);
        for (int i = 1; i <= n1; ++i) {
            for (int j = n2; j > 0; --j) {
                if (nums1[i-1] == nums2[j-1]) dp[j] = dp[j-1] + 1;
                else dp[j] = 0;
                result = (dp[j] > result) ? dp[j] : result;
            }
        }
        return result;
    }
};