class Solution {
public:
    int solve(vector<int>& dp,int sum){
        if(sum == 0)  return 0;
        if(dp[sum] != INT_MAX) return dp[sum];
        int m = INT_MAX;
        for(int i=1 ; i*i <= sum; ++i){
            m = min(m,1+ solve(dp,sum-i*i));
        }
        return dp[sum] = m;
        // it is similar to my approach only taking m = sprt(n) coz we know we need to check only the those m values, but instead of adding to make it n we are subtracting to make it 0
    }
    int numSquares(int n) {
        //similar to coin change
        //int m = sqrt(n); 
        vector<int> dp(n+1,INT_MAX);
        
        return solve(dp,n);
    }
};