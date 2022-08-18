class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        // use two pointers
        // slow one change the element if fast one find not-val number
        int index = 0;
        for (auto &r : nums)
        {
            if (r != val)
                nums[index++] = r;
        }
        return index;
    }
};