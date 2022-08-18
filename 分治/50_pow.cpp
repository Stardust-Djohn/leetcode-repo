class Solution {
public:
    //recursive
    double quick_pow(double x, long n){
        //bese case
        if(n == 0) return 1.0;
        //quickpow
        if(!(n&1)){
            double temp = quick_pow(x, n >> 1);
            return temp * temp;
        }
        return x*quick_pow(x, n-1);
    }
    
    double myPow(double x, int n) {
        long N = n;
        //check if is negative
        return (N > 0) ? quick_pow(x, N) : 1.0/quick_pow(x, -N);
    }
};