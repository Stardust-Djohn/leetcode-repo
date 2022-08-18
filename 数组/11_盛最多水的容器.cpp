class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        //双指针，从外部向内靠近
        //每次检测移动后是否能令最大值更新
        int left = 0, right = height.size() - 1, maxS = -1;
        int sum;
        while (left < right)
        {
            int temp = min(height[left], height[right]);
            sum = temp * (right - left);
            if (sum > maxS)
            {
                maxS = sum;
            }
            //两种情况进行判断：下一个更高/否则另一边进行移动
            // if(height[left+1]<=height[right] && left<height.size()-1) left++;
            // else if(height[right-1]<=height[left] && right>0) right--;
            // else if(left>right) left++;
            // else if(right<=left) right--;
            if (height[left] < height[right])
            {
                do
                {
                    left++;
                } while (left < right && height[left - 1] >= height[left]);
            }
            else
            {
                do
                {
                    right--;
                } while (right > left && height[right + 1] >= height[right]);
            }
        }
        int ans = maxS;
        return ans;
    }
};
//|| height[left]>height[right]
// height[left+1]>height[right] ||