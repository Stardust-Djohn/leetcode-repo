// #include <string>
// using namespace std;

class Solution {
public:
    bool jugde(string sufix, string word) {
        for (int i = 0; i < sufix.size(); ++i) {
            if (sufix[i] != word[i]) return false;
        }
        return true;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        // 遇到空格或者末尾停止读取，进行判断
        int count = 0;
        string tmp;
        for (int i = 0; i <= sentence.size(); i++) {
            if (i == sentence.size() || sentence[i] == ' ') {
                count++;
                if (jugde(searchWord, tmp)) return count;
                tmp.clear();
            }
            else {
                tmp += sentence[i];
            }

        }
        return -1;
    }
};


// int main() {
//     Solution slu;
//     int ans = slu.isPrefixOfWord("i love eating burger", "burg");
//     printf("%d", ans);
//     return 0;
// }