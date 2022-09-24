class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //动态规划完全背包问题
        //dp[i]:表示总长度i的字符串是否等于结果
        //递推：if([j, i] 这个区间的子串出现在字典里 && dp[j]是true) 那么 dp[i] = true
        //dp[0] = true
        //递推方向：外层循环为容量，内层为物品（可以调换）
        int len_s = s.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(len_s + 1, false);
        dp[0] = true;
        for (int j = 1; j <= len_s; ++j) {
            for (int i = 0; i < j; ++i) {
                string word = s.substr(i, j - i); //substr(起始位置，截取的个数)
                if (wordSet.find(word) != wordSet.end() && dp[i]) {
                    dp[j] = true;
                    //cout<<dp[j]<<" ";
                }
            }
        }
        return dp[len_s];
    }
};