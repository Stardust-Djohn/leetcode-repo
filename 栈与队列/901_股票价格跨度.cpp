class StockSpanner {
public:
    // 单调栈
    // 栈中每个元素为<数，下标>二元组
    StockSpanner() {
        // 构造函数
        this->stk.push(make_pair(INT_MAX, -1));
        this->ix = -1;
    }
    // 调用
    int next(int price) {
        ix++;
        while (price >= stk.top().first) {
            stk.pop();
        }
        int ret;
        ret = ix - stk.top().second;
        stk.push({price, ix});
        return ret;
    }
private:
    stack<pair<int, int>> stk; // 二元组分别为数据，下标
    int ix;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */