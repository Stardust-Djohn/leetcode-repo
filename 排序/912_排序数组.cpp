class Solution {
public:
        vector<int> divide_sort_merge(int start, int end, vector<int>& nums){       
        //base case
        if(start >= end){
            vector<int> ret;
            ret.push_back(nums[end]);
            return ret;
        }
        int length = end-start + 1;
        int mid_point = start+length/2 - 1;
        vector<int> left = divide_sort_merge(start, mid_point, nums);
        vector<int> right = divide_sort_merge(mid_point+1, end, nums);        
        return merge(left, right);
        
    }
    
    vector<int> merge(vector<int> left, vector<int> right){
        vector<int> ret;
        //参考：合并两个顺序的链表 的思路
        int length_l = left.size(), length_r = right.size();
        int it_l = 0, it_r = 0;
        while(it_l < length_l && it_r < length_r){
            if(left[it_l] <= right[it_r]) ret.push_back(left[it_l++]);
            else ret.push_back(right[it_r++]);
        }
        //append the rest list
        while(it_l < length_l) ret.push_back(left[it_l++]);
        while(it_r < length_r) ret.push_back(right[it_r++]);
        return ret;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        return divide_sort_merge(0, nums.size()-1, nums);
    }
};