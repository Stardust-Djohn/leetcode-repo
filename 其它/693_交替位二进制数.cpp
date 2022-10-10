class Solution {
public:
    bool hasAlternatingBits(int n) {
        //位运算
        long long a=(n>>1) ^ n;
        return (a & (a+1)) == 0;
    }
};