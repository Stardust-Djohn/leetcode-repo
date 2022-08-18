class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int len = citations.size();
        int l = 0, r = len - 1;
        int mid;
        // edge case
        if (citations[len - 1] == 0)
            return 0;
        // citations[mid]>=len-mid的同时找到mid最小
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (citations[mid] >= len - mid)
            {
                //向左边缩放
                r = mid;
            }
            else if (citations[mid] < len - mid)
            {
                //向右边缩放
                l = mid + 1;
            }
        }
        return len - r;
    }
};