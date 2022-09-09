class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len=nums.size(),ans=INT_MAX,sum=0;
        //enge case
        if(len==0) return 0;
        //vector<int> presum(len+1,0);
        //前缀和
        //for(int i=1;i<=len;++i){
        //    presum[i]=presum[i-1]+nums[i-1];
        //}
        //two pointers
        int a=0,b=0;
        while(b<len){
            sum+=nums[b];
            while(sum>=target){
                ans=min(ans,b-a+1);
                sum-=nums[a++];
            }
            b++;
        }
        return ans==INT_MAX?0:ans;
    }
};