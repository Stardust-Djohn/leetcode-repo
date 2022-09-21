class Solution {
public:
    string convertToBase7(int num) {
        int rem,tmp_n=num;
        //edge case
        if(num==0) return "0";
        string ans;
        tmp_n=(num<0)?-tmp_n:tmp_n;
        while(tmp_n!=0){
            rem=tmp_n%7;
            tmp_n/=7;
            ans+=to_string(rem);
        }
        if(num<0) ans+="-";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};