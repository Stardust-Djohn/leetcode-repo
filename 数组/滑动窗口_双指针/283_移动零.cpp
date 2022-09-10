class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //two pointers
        //edge case
        if(nums.size() == 1) return;
        //last check if nums[last] == 0;pre find nums[pre] != 0
        //then they exchange value
        for(int last = 0; last < nums.size(); ++last){
            if(nums[last] == 0){
                for(int pre = last+1; pre < nums.size(); ++pre){
                    if(nums[pre] != 0){
                        nums[last] = nums[last]^nums[pre];
                        nums[pre] = nums[last]^nums[pre];
                        nums[last] = nums[last]^nums[pre];
                        break;
                    }
                }
            }
        }
    }
};