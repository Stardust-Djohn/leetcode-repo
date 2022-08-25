class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // 根据定义使用排序
        // 时间复杂度：O(nlogn)，其中 n 是数组 arr 的长度
        // 空间复杂度：O(logn)。排序需要 O(logn) 的栈空间
        sort(arr.begin(), arr.end(), [&, x](int &a, int &b)->bool
            { return abs(x-a) < abs(x-b) || a<b && abs(x-a) == abs(x-b);});
        sort(arr.begin(), arr.begin()+k);
        return vector<int> (arr.begin(),arr.begin()+k);
    }
};