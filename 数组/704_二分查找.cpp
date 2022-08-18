class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size(), mid; //左闭右开
        while (l < r)
        { //按照区间定义，右边与左边重合时数组无意义
            mid = l + ((r - l) >> 1);
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
            {
                //在左边区间查找
                r = mid; // r是开区间取不到mid
            }
            else
            {                //右边区间查找
                l = mid + 1; // l是闭区间，能够取到mid，故在定位新的区间时跳过这个已经被证明不能取到的点
            }
        }
        return -1;
    }
};