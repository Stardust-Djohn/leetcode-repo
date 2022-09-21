class Solution {
public:
    int maximumSwap(int num) {
        // 贪心：每一位数字应该不小于所有排它后面的数字；否则找最大的且排最后面的数字与之交换
        // 双指针遍历
        string sn = to_string(num);
        int len = sn.size();
        for (int i = 0; i < len; ++i) {
            // 给每位的数字找可交换的数值时，应该向后找到最大值
            int max_n = sn[i] - '0', id = i;
            int j = i + 1;
            while (j < len) {
                if (max_n <= sn[j] - '0') {
                    max_n = sn[j] - '0';
                    id = j;
                }
                j++;
            }
            if (max_n > sn[i] - '0') {
                swap(sn[i],sn[id]);
                return stoi(sn);
            }
        }
        return stoi(sn);
    }
};