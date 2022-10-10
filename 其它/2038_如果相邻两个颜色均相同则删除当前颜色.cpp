class Solution {
public:
    bool winnerOfGame(string colors) {
        //A，B的操作策略不会互相影响，输赢只看谁允许的操作最多
        int op=0;
        for(int i=1;i<colors.size()-1;++i){
            if(colors[i]=='A' && colors[i-1]=='A' && colors[i+1]=='A') ++op;
            if(colors[i]=='B' && colors[i-1]=='B' && colors[i+1]=='B') --op;
        }
        if(op>0) return true;
        else return false;
    }
};