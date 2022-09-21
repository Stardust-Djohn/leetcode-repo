class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //贪心思路：排序后移除最长的，局部最优可以推出全局最优
        if (intervals.size() == 1) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            //检测到重叠
            if (intervals[i][0] < intervals[i-1][1]) {
                ans++;
                intervals[i][1] = min(intervals[i][1], intervals[i-1][1]); //只留最小的
            }
            //否则不做操作
        }
        return ans;
    }
};