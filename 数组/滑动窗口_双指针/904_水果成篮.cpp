class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //滑动窗口求最大长度
        unordered_map<int, int> window;
        const int k = 2;
        int len = fruits.size(), sum = 0;
        for (int i = 0, j = 0; j < len; j++) {
            window[fruits[j]]++;
            while (window.size() > k) {
                window[fruits[i]]--;
                if (window[fruits[i]] == 0) {
                    window.erase(fruits[i]);
                }
                i++;
            }   
            sum = max(sum, j - i + 1);
        }
        return sum;
    }
};