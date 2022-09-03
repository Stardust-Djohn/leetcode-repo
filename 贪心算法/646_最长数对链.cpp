class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // 贪心算法
        // 每个数组对的第二个数字应当选取最小，这样才有最长
        // 因此在排序之后判断第一个数能否接在前一组的第二数之后
        // 435.无重叠区间-类似题目参考
        sort(pairs.begin(), pairs.end(), [&](vector<int> & a, vector<int> & b)->bool {
            return a[1] < b[1];});
        int curr = INT_MIN, ans = 0;
        for (auto & p : pairs) {
            if (p[0] > curr) {
                ans++;
                curr = p[1];
            }
        }
        return ans;
    }
};