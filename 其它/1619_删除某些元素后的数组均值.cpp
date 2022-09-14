class Solution {
public:
    double trimMean(vector<int>& arr) {
        // 计算需要删去的数
        sort(arr.begin(), arr.end(), less<int>());
        int len = arr.size();
        int d = (int)(len * 0.05);
        return double(accumulate(arr.begin()+d, arr.end()-d,0)) / (len - 2*d);
    }
};