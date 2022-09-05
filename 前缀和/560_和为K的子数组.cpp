class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        ////构造前缀和
        //int len=nums.size();
        //vector<int> presum(len+1,0);
        //for(int i=0;i<len;++i){
        //    presum[i+1]=presum[i]+nums[i];
        //}
        //哈希表
        int len=nums.size();
        unordered_map<int,int> hash;
        hash[0]=1;
        int ans=0,sum_i=0;
        for(int i=0;i<len;++i){
            sum_i+=nums[i];
            if(hash.find(sum_i-k)!=hash.end()){
                ans+=hash[sum_i-k];
            }
            hash[sum_i]++;

        }
        return ans;
    }
};