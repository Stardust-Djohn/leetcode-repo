class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        //哈希表
        int min_sum=INT_MAX;
        vector<string> ans;
        unordered_map<string,int> mp;
        //用哈希表记录每个字段对应的序号
        for(int i=0;i<list1.size();++i){
            mp[list1[i]]=i;
        }
        for(int i=0;i<list2.size();++i){
            //如果list2中的字段在list1中存在
            if(mp.find(list2[i])!=mp.end()){
                //如果小于当前最优答案
                if(i+mp[list2[i]] < min_sum){
                    min_sum=i+mp[list2[i]];
                    ans.clear();
                    ans.emplace_back(list2[i]);
                }
                //如果下标和与最佳答案相同
                else if(i+mp[list2[i]] == min_sum){
                    ans.emplace_back(list2[i]);
                }
            }
        }
        return ans;

    }
};