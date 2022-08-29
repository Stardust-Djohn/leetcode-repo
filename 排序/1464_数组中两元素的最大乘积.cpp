class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 寻找最大的两个数返回结果
        sort(nums.begin(), nums.end(), greater<int>());
        return (nums[0]-1)*(nums[1]-1);
    }
};