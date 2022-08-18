class Solution {
public:
    map<char, string> keyboard = {{'2', "abc"},{'3', "def"},{'4', "ghi"},{'5', "jkl"},{'6', "mno"},{'7', "pqrs"}
                             ,{'8', "tuv"},{'9', "wxyz"}};
    vector<string> ans;
    string one_ans;
    
    bool backtrace(int n, string digits){
        //if max, then back
        if(one_ans.size() == digits.size()){
            ans.push_back(one_ans);
            return true;
        }
        
        char cur_digit = digits[n];
        string cur_str = keyboard[cur_digit];
        for(int i = 0; i < cur_str.size(); ++i){
            one_ans += cur_str[i];
            backtrace(n+1,digits);
            //撤回
            one_ans.pop_back();
            
        }
        return false;
    }
    
    vector<string> letterCombinations(string digits) {
        //edge case
        if(digits.empty()) return ans;
        backtrace(0,digits);
        return ans;
    }
};