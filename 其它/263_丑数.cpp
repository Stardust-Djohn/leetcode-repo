class Solution {
public:
    bool isUgly(int n) {
        //edge case
        if(n<=0) return false;
        vector<int> factor{2,3,5};
        for(auto i:factor){
            while(n%i==0){
                n/=i;
            }
        }
        return n==1;
    }
};