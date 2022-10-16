class Solution {
public:
    int findFa(int x, vector<int> &fa) {
        while (fa[x] != -1) {
            x = fa[x];
        }
        return x;
    }

    void Unit(int a, int b, vector<int> &fa) {
        a = findFa(a, fa);
        b = findFa(b, fa);
        if (a == b) return;
        if (a > b) swap(a, b);
        fa[b] = a;
    }

    bool isSameTeam(int a, int b, vector<int> &fa) {
        return findFa(a, fa) == findFa(b, fa);
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // 并查集
        // 列出每个人的无法合作的人，这些无法合作的人组成并查集结构
        // 建立并查集关系之后，依次检测每个人是否和其无法合作的人同属一个并查集
        vector<vector<int>> hate(n+1);
        vector<int> fa(n+1, -1);
        // 建立每个人无法合作的人的列表
        for (auto & p : dislikes) {
            hate[p[0]].push_back(p[1]);
            hate[p[1]].push_back(p[0]);
        }
        // 建立并查集
        for (int i = 1; i <= n; i++) {
            for(int j = 0; j < hate[i].size(); j++) {
                Unit(hate[i][0], hate[i][j], fa);
            }
        }
        // 检查
        for (int i = 1; i <= n; i++) {
            for(int j = 0; j < hate[i].size(); j++) {
                if (isSameTeam(i, hate[i][j], fa)) return false;
            }
        }
        return true;
    }
};