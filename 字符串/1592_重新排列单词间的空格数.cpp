class Solution {
public:
    // 参考：
    string reorderSpaces(string s) {
        // 遍历字符串
        // 计算空格数量，重新分配
        int n = s.size(), cnt = n, m = 0;
        for(int i = n-1, j = n-1, f = false; i >= 0; --i){
            // f表示i指针上一个所指是否不是空格，用于统计单词数
            // m为单词数
            // cnt表示空格数
            if(s[i] != ' ') {
                swap(s[i], s[j--]);
                m += !f;
                f = true;
                --cnt;
            }
            else if(f) {
                --j;
                f = false;
            }
        }
        for(int i = 0, j = 0, f = false, a = cnt / max(m - 1, 1); i < n; ++i){
            if(s[i] != ' ') {
                swap(s[i], s[j++]);
                f = true;
            }
            // 如果上一个是单词且当前为空格：则跳过分配的空格数
            else if(f) {
                j += a;
                f = false;
            }
        }
        return s;

    }
};