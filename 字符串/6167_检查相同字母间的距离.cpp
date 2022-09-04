class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        // 模拟
        // 用哈希表记录出现距离
        unordered_map<int,int> mp;
        for (int i = 0; i < s.size(); ++i) {
            if (mp.count(s[i] - 'a') == 0) {
                mp[s[i] - 'a'] = i;
            }else {
                mp[s[i] - 'a'] = i - mp[s[i] - 'a'] - 1;
            }  
        }
        for (auto &[c,n] : mp) {
            if (n != distance[c]) return false;
        }
        return true;
    }
};