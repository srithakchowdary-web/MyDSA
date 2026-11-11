class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int m, int n, int i, int j){
        if(i==m-1 && j==n-1) return grid[i][j];
        if(dp[i][j] != -1)  return dp[i][j] ;
        int rt=INT_MAX, down=INT_MAX ;
        if(i < m-1) rt = grid[i][j] + solve(grid, dp, m, n, i+1, j);
        if(j < n-1) down = grid[i][j] + solve(grid, dp, m, n, i, j+1);
        return dp[i][j] = min(rt, down); 
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m,n ;
        m= grid.size();
        n= grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1)) ;
        return solve(grid, dp, m, n, 0, 0);
    }
};