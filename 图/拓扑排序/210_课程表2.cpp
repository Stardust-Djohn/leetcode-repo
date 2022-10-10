class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edge.resize(numCourses);
        indeg.resize(numCourses);
        //记录有向图，并记录各节点的入度大小
        for(auto it:prerequisites){
            edge[it[1]].emplace_back(it[0]);
            ++indeg[it[0]];

        }
        //将入度为0的节点入队
        queue<int> q;
        for(int i=0;i<numCourses;++i){
            if(indeg[i]==0)
                q.emplace(i);
        }
        //拓扑排序
        while(!q.empty()){
            //取出队首的值（入度均为0）
            int t=q.front();
            q.pop();
            //得到答案
            ans.emplace_back(t);
            for(auto v:edge[t]){
                --indeg[v];
                if(indeg[v]==0)
                    q.emplace(v);
            }
        }
        if(ans.size()!=numCourses) return {};
        else return ans;

    }
private:
    vector<vector<int>> edge;
    vector<int> indeg,ans;
    
};