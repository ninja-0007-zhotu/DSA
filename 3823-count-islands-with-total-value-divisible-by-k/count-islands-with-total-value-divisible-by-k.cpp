class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int res = 0,ro = grid.size(),co = grid[0].size();
        for(int i = 0;i < ro;i++){
            for(int j = 0;j < co;j++){
                if(grid[i][j] != 0){
                    res += dfs(grid,i,j,ro,co) % k == 0;
                }
            }
        }
        return res;
    }
    long long dfs(vector<vector<int>> &grid,int r,int c,int &ro,int &co){
        if(r < 0 || c < 0 || r >= ro || c >= co || grid[r][c] == 0){
            return 0;
        }
        long long t = grid[r][c];
        grid[r][c] = 0;
        return t + dfs(grid,r - 1,c,ro,co) + dfs(grid,r + 1,c,ro,co) + dfs(grid,r,c - 1,ro,co) + dfs(grid,r,c + 1,ro,co);
    }
};