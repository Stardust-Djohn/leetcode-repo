class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for (int i = 0; i < prices.size(); ++i) {
            int j = i + 1;
            while (j < prices.size() && prices[j] > prices[i]) {
                ++j;
            }
            prices[i] -= (j >= prices.size()) ? 0 : prices[j];
        }
        return prices;
    }
};