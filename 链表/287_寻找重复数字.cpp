class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        //快慢指针法
        int fast = 0, slow = 0;
        do
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);
        slow = 0;
        while (slow != fast)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};