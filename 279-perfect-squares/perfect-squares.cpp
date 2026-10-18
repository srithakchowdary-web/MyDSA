class Solution {
public:
    int solve(vector<int>& dp, int m, int val){
        if(val == 0) return 0;
        if(dp[val] != -1) return dp[val];
        int v = INT_MAX;
        for(int i=1;i<=m && i*i <= val ;++i){
            v = min(v, 1+solve(dp,m,val-i*i));
        }
        return dp[val]=v;

    }
    int numSquares(int n) {
        int m = sqrt(n);
        vector<int> dp(n+1,-1);
        dp[0]=0;
        return solve(dp,m,n);
    }
};