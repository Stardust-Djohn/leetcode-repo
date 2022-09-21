class Solution {
public:
    long maxScore = 0;
    int cnt = 0;
    int n;
    vector<vector<int>> children;

    int dfs(int node) {
        long score = 1;
        int sum = 1;
        for (int num : children[node]) {
            int t = dfs(num);
            score *= t;
            sum += t;
        }
        if (node != 0) {
            score *= n - sum;
        }
        if (maxScore == score) {
            cnt++;
        } else if (maxScore < score) {
            maxScore = score;
            cnt = 1;
        }
        return sum;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        this->n = parents.size();
        this->children = vector<vector<int>>(n);
        for (int i = 0; i < n; i++) {
            int p = parents[i];
            if (p != -1) 
                children[p].emplace_back(i);
        }
        dfs(0);
        return cnt;
    }
};


//超时
// class Solution {
// public:
//    int find_fa(vector<int> fa,int q){
//        while(q!=fa[q])
//            q=fa[q];
//        return q;
//    }
//
//    void cal_answer(vector<int> fa,int rm_id){
//        fa[0]=0;
//        int len=fa.size();
//        //change father
//        for(int i=0;i<len;++i){
//            if(i==rm_id || fa[i]==rm_id) fa[i]=i;
//        }
//        unordered_map<int,int> mp;
//        for(int i=0;i<len;++i){
//            mp[find_fa(fa,i)]++;
//        }
//        int tmp=1;
//        for(auto it:mp)
//            tmp *= it.second;
//        if(tmp>max_score){
//            max_num=1;
//            max_score=tmp;
//        }else if(tmp==max_score){
//            max_num++;
//        }
//        
//    }
//
//    int countHighestScoreNodes(vector<int>& parents) {
//        int len=parents.size();
//        for(int i=0;i<len;++i){
//            cal_answer(parents,i);
//        }
//        return max_num;
//    }
//
//// private:
//    int max_score=0;
//    int max_num=0;
// };