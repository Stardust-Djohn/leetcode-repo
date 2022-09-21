class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int len=nums.size();
        int max_val,min_val;
        long long ans=0;
        for(int i=0;i<len;++i){
            max_val=INT_MIN,min_val=INT_MAX;
            for(int j=i;j<len;++j){
                max_val=max(max_val,nums[j]);
                min_val=min(min_val,nums[j]);
                ans+=max_val-min_val;
            }
        }
        return ans;
    }
};