class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int index=0;
        for(const int num:data){
            if(index==0){
                if(num>>5 == 0b110) index=1;
                else if(num>>4 == 0b1110) index=2;
                else if(num>>3 == 0b11110) index=3;
                else if(num>>7 != 0) return false;
            }else{
                if(num>>6 != 0b10) return false;
                --index;
            }
        }
        return index==0;
    }
};