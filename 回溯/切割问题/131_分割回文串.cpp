class Solution {
public:
    vector<vector<string>> partition(string s) {
        //回溯
        //截取的位置与回文的判断
        backtrace(s, 0);
        return ans;
    }
private:
    vector<string> path;
    vector<vector<string>> ans;

    void backtrace(const string & s, int startid) {
        //递归结束条件
        if (startid >= s.size()) {
            //说明此时已经找到一组方案
            ans.emplace_back(path);
            return ;
        }

        for (int i = startid; i < s.size(); ++i) {
            //单层遍历逻辑
            if (isPalindrome(s, startid, i)) { //如果是则放入路径
                string str = s.substr(startid, i - startid + 1);
                path.push_back(str);
            }
            else { //否则跳过本轮
                continue;
            }
            backtrace(s, i + 1);
            path.pop_back(); //撤回
            
        }
        return ;
    }
    bool isPalindrome(const string &str, int start, int end) {
        for (int i = start, j = end; i < j; ++i, --j) {
            if (str[i] != str[j]) return false;
        }
        return true;
    }
};