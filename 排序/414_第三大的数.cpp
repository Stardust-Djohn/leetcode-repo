class Solution {
public:
    int thirdMax(vector<int>& nums) {
        //将 vector 转换为 set，set 数据结构自动去重
        set<int>s(nums.begin(), nums.end());
        //再将 set 转换为 vector 进行使用
        nums.assign(s.begin(), s.end());
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n<3) return nums[n-1];
        return nums[n-3];
    }
};
