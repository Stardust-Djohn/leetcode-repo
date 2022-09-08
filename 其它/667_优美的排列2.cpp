class Solution {
public:
    vector<int> constructArray(int n, int k) {
        // k=1,2,3,...n
        // k=1,顺序排列1,2,3,...n
        // k=n-1,排列为1,n,2,n-1,3...
        // 到一般情况：[1,2,⋯,n−k,n,n−k+1,n−1,n−k+2,⋯],据此构造
        vector<int> ans;
        for (int i = 1; i < n-k; i++) {
            ans.push_back(i);
        }
        for (int i = n-k, j = n; i <= j; ++i, --j) {
            ans.push_back(i);
            if (i != j) {
                ans.push_back(j);
            }
        }
        return ans;
    }
};