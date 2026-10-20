class Solution {
public:
    int solve(vector<int>& coins, vector<vector<int>>& dp, int val, int idx){
        if(val < 0 ) return 0; 
        if(val == 0) return 1;
        if(dp[idx][val] != -1)
            return dp[idx][val];
        int ways = 0;
        int i, n=coins.size();
        for(i=idx;i<n;++i){
           ways += solve(coins,dp,val-coins[i],i); // i coz it can be reused 
        }
        return dp[idx][val]=ways;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1 ,-1));
        return solve(coins,dp,amount,0);
    }
};