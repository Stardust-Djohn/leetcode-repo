class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        int k = j;
        vector<int> ans(nums.size());
        while(i <= j) {
            int a = nums[i] * nums[i];
            int b = nums[j] * nums[j];
            if (a < b) {
                ans[k--] = b;
                j--;
            }
            else {
                ans[k--] = a;
                i++;
            }
        }
        return ans;
    }
};