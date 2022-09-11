class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //get the length
        int n = nums.size();
        //遍历数组，遇到数x，则在nums[x-1]处+nums.size()
        for(int i = 0; i < n; ++i){
            nums[(nums[i]-1)%n] += n;
        }
        //再遍历一遍，小于n的数的位置就是缺失的数字，写入另一个数组容器中
        vector<int> ans;
        for(int j = 0; j < n; ++j){
            if(nums[j] <= n){
                ans.push_back(j+1);
            }
        }
        return ans;
    }
};