class Solution {
public:
    int minAddToMakeValid(string s) {
        while(s.find("()") != s.npos) {
            s = s.replace(s.find("()"),2,"");
        }
        return s.size();
    }
};