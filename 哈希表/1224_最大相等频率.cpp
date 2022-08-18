class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        // 用哈希表记录
        int ans, maxFreq = 0;
        unordered_map<int, int> freq, count; // freq表示出现i次的数有多少个，count表示每个数出现x次
        // 遍历nums时进行判断
        for (int i = 0; i < nums.size(); i++) {
            if (count[nums[i]] > 0) {
                freq[count[nums[i]]]--; //freq上出现的该数的次数+1
            }
            count[nums[i]]++;
            freq[count[nums[i]]]++;  //登记更新freq
            maxFreq = max(maxFreq, count[nums[i]]);  //比较出现的最高频率
            /* 
            符合题意的几个条件：
            1.目前出现的数最大频率为1，即所有数只出现过一次 
            2.当前数出现达到最高频率maxFreq的只有一次，其它出现的所有数的频率均为maxFreq-1
            3.当前出现的i-1个数出现频率为maxFreq，剩余一个数仅出现1次
            */
            bool flag = maxFreq == 1 || 
                        (freq[maxFreq] == 1 && freq[maxFreq-1] == count.size()-1) ||
                        (freq[maxFreq] == count.size()-1 && freq[1] == 1);
            if (flag) ans = i + 1;
        }
        return ans;

    }
};