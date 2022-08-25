class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        vector<int> bnd_left(len), bnd_right(len);
        stack<int> mono_stack;
        //get the left spreading bondary by mono stack
        for(int i = 0; i < len; ++i){
            //ensure that stack is mono stack
            while(!mono_stack.empty() && heights[i] <= heights[mono_stack.top()]){
                mono_stack.pop();
            }
            //可以发现，此时单调栈的栈顶元素就是当前柱子向左扩散的边界
            bnd_left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            //单调栈将当前柱的位置入栈
            mono_stack.push(i);         
        }
        
        mono_stack = stack<int>(); //clear mono stack
        //the same as the bondary left, create right bondary
        for(int i = len-1; i >= 0; --i){
            //ensure that stack is mono stack
            while(!mono_stack.empty() && heights[i] <= heights[mono_stack.top()]){
                mono_stack.pop();
            }
            //同理，此时单调栈的栈顶元素就是当前柱子向右扩散的边界
            bnd_right[i] = (mono_stack.empty() ? len : mono_stack.top());
            //单调栈将当前柱的位置入栈
            mono_stack.push(i);         
        }        
        
        //根据当前柱的高度以及其可以向两边扩散的范围来求出该柱可以得到的最大面积，并在所有柱中求最大
        int ans = 0;
        for(int i = 0; i < len; ++i){
            ans = max(ans, (bnd_right[i]-bnd_left[i]-1)*heights[i]);
        }
        return ans;
    }
};