class Solution {
public:
    vector<vector<int>> ans;
    vector<int> one_ans;
    map<int, bool> used_list; //记录元素是否被使用过
    
    bool backtrace(vector<int>& one_ans, int cur, vector<int>& nums){
        //if list full
        if(one_ans.size() == nums.size()){
            ans.push_back(one_ans);
            return true;
        } 
        
        for(int i = cur; i < nums.size(); ++i){
            //make a choose: if not used
            for(int j = 0; j < used_list.size(); ++j){
                //检查是否使用过
                if(used_list[nums[j]] == true){
                    //做选择并回溯
                    one_ans.push_back(nums[j]);
                    used_list[nums[j]] = false;
                    backtrace(one_ans, i+1, nums);
                    //撤回操作
                    one_ans.pop_back();
                    used_list[nums[j]] = true;
                }
            }

        }
        return true;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            used_list[nums[i]] = true;
        }
        backtrace(one_ans, 0, nums);
        return ans;
    }
};