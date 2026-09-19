class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0);
        int ans = -1;

        for (int i = 0; i < n; i++) {

            if (vis[i] != 0)
                continue;

            int node = i;
            int steps = 0;

            unordered_map<int, int> depth;

            while (node != -1 && vis[node] == 0) {
                vis[node] = 1;
                depth[node] = steps++;
                node = edges[node];
            }

            if (node != -1 && vis[node] == 1) {
                ans = max(ans, steps - depth[node]);
            }

            node = i;

            while (node != -1 && vis[node] == 1) {
                vis[node] = 2;
                node = edges[node];
            }
        }

        return ans;
    }
};