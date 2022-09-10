class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int len=s.size();
        vector<int> ans,presum(len),left(len),right(len);
        for (int i = 0, j = len - 1, p = -1, q = -1,sum=0; i < len; i++, j--) {
            if (s[i] == '|') p = i;
            if (s[j] == '|') q = j;
            left[i] = p; right[j] = q;
            presum[i] = s[i] == '*' ? ++sum : sum;
        }
        for (auto& query : queries) {
            int x = right[query[0]], y = left[query[1]];
            ans.push_back(x == -1 || y == -1 || x >= y ? 0 : presum[y] - presum[x]);
        }
        return ans;
    }
};