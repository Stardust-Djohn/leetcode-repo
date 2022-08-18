class Solution {
public:
    int search(vector<int>& nums, int target) {
        //num[mid]一定落转一个有序区间中
        int len=nums.size();
        if(len==0) return -1;
        
        int l=0,r=len-1;
        while(l<r){
            //根据分支逻辑调整中间数的取法
            int mid=l+(r-l+1)/2;
            if(nums[mid]<nums[r]){
                //[mid,r]区间有序
                if(nums[mid]<=target && target<=nums[r]){
                    l=mid;
                }else{
                    r=mid-1;
                }
            }else{
                //此时 nums[mid] >= nums[right]，注意此时 mid 可能与 right 重合
                // 数组前半部分有序，即 [left..mid] 有序，为了与上一个分支的逻辑一致，认为 [left..mid - 1] 有序
                if(nums[l]<=target && target<=nums[mid-1]){
                    r=mid-1;
                }else{
                    l=mid;
                }
                // 补充说明：由于中间数上取整，在区间只剩下两个元素的时候，mid 与 right 重合，逻辑走到 else 分支里
                // 此时恰好 if 这个分支看到的是 left 和 mid - 1 ，用到的都是 == 号，等价于判断 nums[left] == target
                // 因此依然可以缩减区间，注意这里 if 里面的 nums[left] <= target && target <= nums[mid - 1] ，
                // 不可以写成 nums[left] <= target && target < nums[mid]

            }
        }
        if(nums[l]==target)
            return l;
            
        return -1;
    }
};