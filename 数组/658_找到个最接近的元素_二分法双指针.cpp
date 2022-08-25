class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // 二分法找到位置
        int len = arr.size();
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right-1;
        // 从这个边界开始向上/下游寻找
        while (k--) {
            if (left < 0) right++;
            else if (right > len - 1) left--;
            else if (x - arr[left] <= arr[right] - x) left--;
            else right++;
        }
        return vector<int> (arr.begin() + left + 1,arr.begin() + right);
    }
};