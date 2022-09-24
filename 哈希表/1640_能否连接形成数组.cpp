class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        // 用哈希表记录每个断片的起始下标
        // 对于每个断片检查每个元素是否对应
        unordered_map<int, int> index;
        for (int i = 0; i < pieces.size(); i++) {
            index[pieces[i][0]] = i;
        }

        for (int i = 0; i < arr.size();) {
            auto it = index.find(arr[i]);
            if (it == index.end()) return false;
            for (auto & x : pieces[it->second]) {
                if (x != arr[i++]) return false;
            }
        }
        return true;
    }
};