class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        //指针从最右边开始，同时记录最大值
        //每次往前面移动一个单位，直接将目前记录的最大值写入
        int length = arr.size();
        int max_num = arr[length-1];
        for(int i = length-1; i >= 0; --i){
            if(i == length-1) arr[i] = -1;
            else{
                if(arr[i] > max_num){
                    arr[i] = arr[i]^max_num;
                    max_num = arr[i]^max_num;
                    arr[i] = arr[i]^max_num;
                    continue;
                }
                arr[i] = max_num;
            } 


        }
        return arr;
    }
};