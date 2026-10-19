class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<char> visited(m * n, 0);
        int r = 0, c = 0;
        visited[0] = 1;

        while (true) {
            int nr = r, nc = c;
            char d = grid[r][c];

            if (d == 'L') --nc;
            else if (d == 'R') ++nc;
            else if (d == 'U') --nr;
            else ++nr;

            if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr * n + nc]) {
                return {r, c};
            }

            r = nr;
            c = nc;
            visited[r * n + c] = 1;
        }
    }
};