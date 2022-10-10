class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edge.resize(numCourses);
        indeg.resize(numCourses);
        for(auto it:prerequisites){
            edge[it[1]].emplace_back(it[0]);
            ++indeg[it[0]];

        }
        queue<int> q;
        for(int i=0;i<numCourses;++i){
            if(indeg[i]==0)
                q.emplace(i);
        }
        while(!q.empty()){
            int t=q.front();
            q.pop();
            ++ans;
            for(auto v:edge[t]){
                --indeg[v];
                if(indeg[v]==0)
                    q.emplace(v);
            }
        }
        if(ans!=numCourses) return false;
        else return true;
    }
private:
    vector<vector<int>> edge;
    vector<int> indeg;
    int ans=0;
};