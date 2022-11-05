class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // 双指针
        string ret;
        int len1 = word1.size(), len2 = word2.size();
        int p1 = 0, p2 = 0;
        while (p1 < len1 && p2 < len2) {
            ret += word1[p1++];
            ret += word2[p2++];
        }
        if (p1 == len1) {
            while (p2 < len2) ret += word2[p2++];
        }
        else {
            while (p1 < len1) ret += word1[p1++];
        }
        return ret;
    }
};