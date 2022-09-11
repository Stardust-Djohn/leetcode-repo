class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int even_num = 0;
        for(auto r : nums){
            int count = 0;
            while(r != 0){
                ++count;
                r /= 10;
            }
            if(count%2 == 0){
                ++even_num;
            }
        }
        return even_num;
    }
};