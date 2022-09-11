class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int len=nums.size();
        //edge case
        if(len==1) return nums;
        //two pointers
        int i=0,j=len-1;
        while(i<j){
            if(nums[i]%2 > nums[j]%2){
                swap(nums[i],nums[j]);
                ++i;
                --j;
            }
            if(nums[i]%2 == 0) ++i;
            if(nums[j]%2 == 1) --j;
        }
        return nums;
    }
};