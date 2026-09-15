class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) {
            return true;
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        vector<bool> visited(n, false);
        visited[source] = true;
        q.push(source);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < adj[cur].size(); i++) {
                if (!visited[adj[cur][i]]) {
                    if (adj[cur][i] == destination) {
                        return true;
                    }
                    q.push(adj[cur][i]);
                    visited[adj[cur][i]] = true;
                }
            }
        }
        return false;
    }
};