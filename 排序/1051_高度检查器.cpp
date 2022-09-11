class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // //bulit a sort array
        // vector<int> cali = heights;
        // sort(cali.begin(), cali.end());
        // int not_match = 0;
        // //compare two arraies
        // for(int i = 0; i < heights.size(); ++i){
        //     if(heights[i] != cali[i]) ++not_match;
        // }
        // return not_match;

        // 桶排序
        int ans = 0;
        map<int,int> mp;
        for (auto &i : heights) {
            mp[i]++;
        }
        int i = 0;
        for (auto &[id,n] : mp) {
            while(n--) {
                if (heights[i++] != id) {
                    ans++;
                }
            }
        }
        return ans;
    }
};