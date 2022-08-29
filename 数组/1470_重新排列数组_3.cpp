class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // 位运算，实现原地算法
        // 根据题意，数组的数在二进制10位以内
        for (int i = 0; i < n * 2;++i) {
            //把结果保存在低位，原来的结果保存在高位
            int j = i < n ? 2 * i : 2 * (i - n) + 1;
            nums[j] |= (nums[i] & 1023) << 10;
        }
        for (auto &i : nums) {
            i >>= 10;
        }
        return nums;
    }
};