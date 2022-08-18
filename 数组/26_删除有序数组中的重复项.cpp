class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        // get length
        int length = nums.size();
        // if length == 0
        if (length == 0)
            return 0;
        //
        int pre = 1, last = 1;
        while (pre < nums.size())
        {
            if (nums[pre] != nums[pre - 1])
            {
                nums[last] = nums[pre];
                ++last;
            }
            ++pre;
        }
        return last;
    }
};