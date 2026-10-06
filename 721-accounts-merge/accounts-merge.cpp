class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(unordered_map<string, int>& mp) {
        int n = mp.size();

        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v)
            return;

        if(rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;

        else if(rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;

        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v)
            return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        // email -> account index
        unordered_map<string, int> mapNode;

        // First create the email mapping
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if(mapNode.find(mail) == mapNode.end()) {
                    mapNode[mail] = i;
                }
            }
        }

        /*
            Your DSU constructor uses mp.size().

            So we need the DSU to have n nodes.
            We create a temporary map with n entries.
        */
        unordered_map<string, int> dsuMap;

        for(int i = 0; i < n; i++) {
            dsuMap[to_string(i)] = i;
        }

        DisjointSet ds(dsuMap);

        // Merge accounts having common emails
        for(int i = 0; i < n; i++) {

            for(int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if(mapNode[mail] != i) {
                    ds.unionBySize(i, mapNode[mail]);
                }
            }
        }

        // Store emails according to their ultimate parent
        vector<list<string>> merged(n);

        for(auto it : mapNode) {

            string mail = it.first;
            int node = it.second;

            int parent = ds.findUPar(node);

            merged[parent].push_back(mail);
        }

        vector<vector<string>> ans;

        // Create final answer
        for(int i = 0; i < n; i++) {

            if(merged[i].empty())
                continue;

            merged[i].sort();

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for(auto mail : merged[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};