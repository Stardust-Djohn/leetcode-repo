class Solution {
public:
    bool judge(vector<int>& nums, int i, int j) {
        for (int ii = i; ii <= j; ii++) {
            for (int jj = ii + 1; jj <= j; jj++) {
                if ((nums[ii] & nums[jj]) != 0x0) return false;
            }
        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        // 滑动窗口
        int ans = 1;
        int i = 0, j = 0;
        int len = nums.size();
        while (i < len && j < len) {
            while (j < len && judge(nums, i, j)) {
                ans = max(ans, j - i + 1);
                j++;
            }
            i++;
            j = i;
        }
        return ans;
    }
};