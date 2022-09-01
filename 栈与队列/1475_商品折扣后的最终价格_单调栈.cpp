class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans = prices;
        // 单调栈，空间换时间
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }
            ans[i] -= (st.empty()) ? 0 : st.top();
            st.push(prices[i]);
        }
        return ans;
    }
};