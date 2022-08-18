class Solution {
public:  
    bool backtrace(int left, int right, string& one_ans, vector<string>& ans){
        //all parentheses used up
        if(left == 0 && right == 0){
            ans.push_back(one_ans);
            return true;
        }
        
        if(right < left) return false;
        if(left < 0 || right < 0) return false;
                
        one_ans.push_back('(');
        backtrace(left-1, right, one_ans, ans);
        one_ans.pop_back();


        one_ans.push_back(')');
        backtrace(left, right-1, one_ans, ans);
        one_ans.pop_back();
     

        return true;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string one_ans;
        backtrace(n, n, one_ans, ans);
        return ans;
    }
};