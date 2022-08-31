class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // 模拟过程
        int len = pushed.size();
        stack<int> stk;
        for (int i = 0, j = 0; i < len; i++) {
            stk.emplace(pushed[i]);
            while (!stk.empty() && stk.top() == popped[j]) {
                stk.pop();
                j++;
            }
        }
        return stk.empty();
        
    }
};