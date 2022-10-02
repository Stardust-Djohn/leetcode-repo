class Solution {
public:
    bool checkOnesSegment(string s) {
        // 检测连续的1的次数
        // 无前导0：检测0之后是否有1
        int i = 0;
        while (i < s.size()) {
            if (s[i] != '0') i++;
            else {
                while (i < s.size()) {
                    i++;
                    if (s[i] == '1') return false;
                }
            }
        }
        return true;
    }
};