class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        // 模拟
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0) return ans;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= abs(k); j++) {
                // 注意处理正负数
                ans[i] += (k > 0) ?  code[(n+i+j)%n] : code[(n+i-j)%n];
            }
        }
        return ans;
    }
};