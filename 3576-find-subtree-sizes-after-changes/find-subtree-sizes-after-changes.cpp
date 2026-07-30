class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        vector<vector<int>> tree(n);
        for (int i = 1; i < n; i++)
            tree[parent[i]].push_back(i);

        vector<int> newParent = parent;

        vector<vector<int>> stack(26);

        function<void(int)> dfs = [&](int u) {
            int c = s[u] - 'a';

            if (!stack[c].empty() && u != 0)
                newParent[u] = stack[c].back();

            stack[c].push_back(u);

            for (int v : tree[u])
                dfs(v);

            stack[c].pop_back();
        };
        dfs(0);
        vector<vector<int>> newTree(n);
        for (int i = 1; i < n; i++)
            newTree[newParent[i]].push_back(i);

        vector<int> ans(n);

        function<int(int)> dfs2 = [&](int u) {
            int sz = 1;
            for (int v : newTree[u])
                sz += dfs2(v);
            ans[u] = sz;
            return sz;
        };

        dfs2(0);

        return ans;
    }
};