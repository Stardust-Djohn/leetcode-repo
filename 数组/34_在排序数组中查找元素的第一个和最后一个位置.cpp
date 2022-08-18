class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto i1=lower_bound(nums.begin(),nums.end(),target);
        auto i2=upper_bound(nums.begin(),nums.end(),target);
        vector<int> ans;

        if(i1==nums.end() && i2==nums.end())
            return vector<int>{-1,-1};
        else if(*i1!=target)
            return vector<int>{-1,-1};
        else if(i1!=nums.end()){
            ans.push_back(static_cast<int>(i1-nums.begin()));
            ans.push_back(static_cast<int>(i2-nums.begin()-1));

        }
        return ans;
    }
};