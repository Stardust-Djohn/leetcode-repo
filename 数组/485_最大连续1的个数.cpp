class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_n = 0;
        int temp = 0;
        for(auto r : nums){
            if(r == 1)
                ++temp;
            else{
                if(temp > max_n) max_n = temp;
                temp = 0;
            }   
        }
        return max(max_n,temp);
    }
};