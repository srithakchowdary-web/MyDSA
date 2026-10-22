class Solution {
public:
    
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        dp[1]=1;
        int i,j,k;
        for(i=2;i<=n;++i){
            //try every split of 2
            for(j=1;j<i;++j){
                k = i-j;
                int j1 = max(j, dp[j]);
                int k1 = max(k, dp[k]);
                dp[i] = max(dp[i], j1*k1);
            }
        }
        return dp[n];
    }
};