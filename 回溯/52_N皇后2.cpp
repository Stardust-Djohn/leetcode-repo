class Solution {
public:
    vector<pair<int, int>> queens;
    
    bool is_not_be_attacked(int row, int col){
        for(auto r : queens){
            //edge case: empty
            if(queens.empty()) return true;
            //if be attacked
            if(r.first == row || r.second == col || abs(r.first-row) == abs(r.second-col)){
                return false;
            }
        }
        return true;
    }      
    
    int backtrack_nqueen(int n, int row, int count){
        //iterate through columns at the curent row.
        for(int col = 0; col < n; ++col){
            if(is_not_be_attacked(row, col)){
                //explore this partial candidate solution, and mark the attacking zone
                queens.push_back(make_pair(row, col));
                //we reach the bottom, we find a solution!                
                if(row + 1 == n) ++count;
                //else move on to the next row
                else count = backtrack_nqueen(n, row + 1, count);
                                    
                //backtrack, i.e. remove the queen and remove the attacking zone.
                queens.pop_back();
            }            
        }
        return count;
    }
    
    int totalNQueens(int n) {
        return backtrack_nqueen(n, 0, 0);
    }
};