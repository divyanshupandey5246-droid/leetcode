class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>& adj, vector<bool>& visited, int u, int v){
        if(u == v)
            return true;

        visited[u] = true;

        for(auto x : adj[u]){
            if(!visited[x]){
                if(dfs(adj, visited, x, v))
                    return true;
            }
        }

        return false;  
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int m = edges.size();
        int n = edges.size() + 1;  // FIX 1

        vector<bool> visited(n, false);
        unordered_map<int,vector<int>> adj;

        for(int i = 0; i < m; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            fill(visited.begin(), visited.end(), false); // FIX 2

            if(adj.find(u) != adj.end() && 
               adj.find(v) != adj.end() && 
               dfs(adj, visited, u, v)){
                return edges[i];
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        } 

        return {};
    }
};