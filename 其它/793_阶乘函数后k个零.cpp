class Solution {
public:
    // leetcode172
    int trailingZeroes(int n) {
        // 计算末尾0，需要看阶乘中2、5因数的数量
        // 2以及2的倍数的数量大于5的，因此根据5的因子的个数来判断0
        int count=0;
        while(n!=0){
            n=n/5;
            count+=n;
        }
        return count;
    }
    long long help(int k) {
        // 二分法
        long long r = 5LL * k; // 右边界为什么这么取，详见官方解析中的数学推导
        long long l = 0;
        while (l <= r) {
            auto mid = l + r >> 1;
            if (trailingZeroes(mid) < k) {
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        return r + 1;
    }

    int preimageSizeFZF(int k) {
        // 看题目，k数量级很大，应该存在简便的计算规律
        // leetcode172求n！含有多少末尾0
        // nk表示阶乘后的结果末尾0为k个的最小的数
        // 题目需要求nk+1-nk
        return help(k+1) - help(k);
    }
};