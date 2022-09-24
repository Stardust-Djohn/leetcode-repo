class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //回溯：收集所有的递归回溯节点
        backtrace(nums, 0);
        return ans;
    }

private:
    vector<int> path;
    vector<vector<int>> ans;

    void backtrace(vector<int>& nums, int startid) {
        ans.emplace_back(path);  // 收集子集，要放在终止添加的上面，否则会漏掉自己
        //递归终止条件：到达末尾
        if (startid >= nums.size()) {
            return ;
        }

        //求取子集问题，不需要任何剪枝,因为子集就是要遍历整棵树
        for (int i = startid; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtrace(nums, i + 1);
            //撤回
            path.pop_back();
        }
        return;
    }
};