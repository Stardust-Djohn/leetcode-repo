class Solution {
public:
    int minOperations(vector<string>& logs) {
        // 记录层数
        int ans = 0;
        for (auto & s : logs) {
            if (s == "../") {
               ans = (ans > 0) ? ans-1 : ans;
            }
            else if (s == "./") continue;
            else ans++;
        }
        return ans;
    }
};