class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //利用哈希表map存储另一个数
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int t_id = target - nums[i];
            if (hash.find(t_id) != hash.end())
                return vector<int>{i, hash[t_id]};
            hash[nums[i]] = i;
        }
        return {};
    }
};