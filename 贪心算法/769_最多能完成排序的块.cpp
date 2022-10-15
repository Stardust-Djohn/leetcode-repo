class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // 分块排列
        // 贪心算法：分割排序的块的数组总和与下标总和相等
        // 两个推论：A=B+C，A，B能分割排序，则C也能分割排序；B、C能分割排序，则A也能分割排序
        int ans = 0;
        int sum_id = 0, sum_num = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum_id += i;
            sum_num += arr[i];
            ans += (sum_id == sum_num) ? 1 : 0;
        }
        return ans;
    }
};