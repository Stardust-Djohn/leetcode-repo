class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int width=grid[0].size(),depth=grid.size();
        vector<int> ans(width,-1);
        for(int i=0;i<width;i++){
            //过程判断
            int col=i;
            for(auto &row:grid){
                int dir=row[col];
                col+=dir;
                if (col < 0 || col == width || row[col] != dir) { // 到达侧边或 V 形
                    col = -1;
                    break;
                }
            }
            if(col>=0)
                ans[i]=col;
        }
        return ans;
    }
};