class Solution {
public:
    void backtrace(int id){
        if (tmp.size() == k) {
            ans.emplace_back(tmp);
            return ;
        }
        for (int i = id+1; i <= num; ++i) {
            tmp.push_back(i);
            backtrace(i);
            tmp.pop_back();
        }
        return ;
    }

    vector<vector<int>> combine(int n, int k) {
        this->num = n;
        this->k = k;
        backtrace(0);
        return ans;
    }
private:
    int num, k;
    vector<int> tmp;
    vector<vector<int>> ans;
};