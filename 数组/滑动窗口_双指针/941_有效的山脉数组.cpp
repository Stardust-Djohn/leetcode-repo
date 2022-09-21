class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        //the length of array should greater than 3
        if(arr.size() < 3) return false;
        //two pointers traverse
        int i = 0, j = arr.size()-1;
        while(i < arr.size()-1 && arr[i] < arr[i+1]){
            ++i;
        }
        while(j > 0 && arr[j] < arr[j-1]){
            --j;
        }
        //check
        if(i == arr.size()-1 || j == 0){
            return false;
        }
        else{
             if(i == j) {
                return true;
            }
            else return false;
        }

    }
};