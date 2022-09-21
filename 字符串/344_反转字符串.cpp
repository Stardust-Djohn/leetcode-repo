class Solution {
public:
    //helper
    void helper(vector<char>& s, int l, int r){
        if(l >= r) return;
        else{
            helper(s, l+1, r-1);
            char temp;
            temp = s[l];
            s[l] = s[r];
            s[r] = temp;            
        }
    }
    
    void reverseString(vector<char>& s) {
        //recursive
        helper(s, 0, s.size()-1);
    }
};