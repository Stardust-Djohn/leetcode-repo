class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // 判断标准：比较两个数组是否相等
        // 只要两个数组相等，就一定能通过翻转实现
        /*
            排序消耗 O(n×logn) 复杂度，判断是否相同消耗O(n) 复杂度；
            快速排序递归深度平均为 O(logn)；
        */
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return target == arr;
    }
};

/*
// 时空复杂度均为O（n）
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // 判断标准：比较两个数组是否相等
        // 只要两个数组相等，就一定能通过翻转实现
        unordered_map<int, int> comp;
        for (auto i : target) {
            comp[i]++;
        }
        for (auto i : arr) {
            comp[i]--;
        }
        for (auto [c,_] : comp) {
            if (comp[c] != 0) return false;
        }
        return true;
    }
};


*/