class Solution {
public:
    int solve(vector<int>& coins, vector<int>& dp, int val){
        if(val < 0) return INT_MAX; 
        if(val == 0) return 0;
        if(dp[val] != -1) return dp[val];
        int ways =  INT_MAX;
        int n = coins.size();
        for(int i=0;i<n;++i){
            int sub = solve(coins,dp,val-coins[i]);  // if the coins[i]>val then it will return int_max
            if(sub != INT_MAX) ways = min(ways, 1+sub);
        }
        return dp[val]=ways;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans = solve(coins,dp,amount);
        return ans == INT_MAX ? -1 : ans;
    }
};