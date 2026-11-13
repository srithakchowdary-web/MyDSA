class Solution {
public:
    int solve(vector<vector<int>>& dp, int m, int n, int i, int j){
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        //only 2 possible ways either right or down
        int rt=0,down=0;
        if(j < n-1) rt = solve(dp, m, n, i, j+1);
        if(i < m-1) down = solve(dp, m,n ,i+1, j);
        return dp[i][j] = (rt+down);
    }
    int uniquePaths(int m, int n) {
        // dp depends on only a single state=> dp[i]=no.of ways to reach it;
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return solve(dp, m,n , 0,0);
    }
};