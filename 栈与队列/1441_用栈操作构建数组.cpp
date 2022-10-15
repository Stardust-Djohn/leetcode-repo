class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        // 模拟过程
        // 用一个下标来与当前数组中的数比较
        // 下标相等则只进行push操作，否则进行push与pop操作，同时下标+1
        vector<string> ret;
        int ix = 1, i = 0;
        int tg = *(target.end()-1);
        // cout << tg <<endl;
        while (ix <= tg) {
            if (ix == target[i]) {
                ret.push_back("Push");
                i++;
            }
            else {
                ret.push_back("Push");
                ret.push_back("Pop");
            }
            ix++;
        }
        return ret;
    }
};