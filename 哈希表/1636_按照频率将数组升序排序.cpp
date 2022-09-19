class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // 哈希表
        unordered_map<int, int> hs;
        for (auto & i : nums) {
            hs[i]++;
        }
        // 匿名函数
        sort(nums.begin(), nums.end(), [&](const int a, const int b) {
            if (hs[a] != hs[b]) {
                return hs[a] < hs[b];
            }
            return a > b;
        });
        return nums;
    }
};