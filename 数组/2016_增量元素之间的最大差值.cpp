class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        //两重循环，中间判断减少次数
        int ans=-1;
        int len=nums.size();
        for(int i=0;i<len-1;++i){
            if(i!=0 && nums[i-1]<nums[i]) continue;
            for(int j=i+1;j<len;++j){
                if(j-1!=i && nums[j-1]>nums[j]) continue;
                int temp=nums[j]-nums[i];
                ans=(temp>0 && temp>ans)?temp:ans;
            }
        }
        return ans;
    }
};