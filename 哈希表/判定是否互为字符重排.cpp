class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        // 排序后比较
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};

// class Solution {
// public:
//     bool CheckPermutation(string s1, string s2) {
//         // 哈希表
//         unordered_map <char, int> mp;
//         for (auto c : s1) {
//             mp[c]++;
//         }
//         for (auto c : s2) {
//             mp[c]--;
//         }
//         for (auto &it : mp) {
//             if (it.second != 0)
//                 return false;
//         }
//         return true;
//     }
// };