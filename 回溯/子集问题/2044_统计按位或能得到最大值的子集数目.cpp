class Solution {
public:
    void dfs(int id,int val){
        if(id==len){
            if(val>max){
                max=val;
                ans=1;
            }else if(val==max){
                ans++;
            }
        }
        else{
            //对于每个元素，都有选择或者不选择两种路径
            //将位运算的结果作为参数传递，节省了计算空间，将【数集合】与【计算子集结果】两步合并
            dfs(id+1,val);
            dfs(id+1,val | _nums[id]);
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        this->_nums=nums;
        this->len = nums.size();
        dfs(0,0);
        return ans;
    }
private:
    int max=0,ans=0,len;
    vector<int> _nums;
};