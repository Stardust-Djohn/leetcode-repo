class Solution {
public:
    int scoreOfParentheses(string s) {
        // 用栈模拟
        stack<int> sk;
        sk.push(0);
        for (auto & c : s) {
            if (c == '(') {
                sk.push(0);
            }
            else {
                int v = sk.top();
                sk.pop();
                sk.top() += max(2*v, 1);
            }
        }
        return sk.top();
    }
};