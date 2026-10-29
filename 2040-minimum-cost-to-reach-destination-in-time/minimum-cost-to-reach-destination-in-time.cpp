class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size(), time,i ;
        vector<vector<int>> dp(n, vector<int>(maxTime+1, INT_MAX));
        dp[0][0] = passingFees[0];
        for(time = 1;time<=maxTime;++time){
            for(auto& e : edges){
                int intial_city = e[0];
                int dest_city = e[1];
                int t = e[2];
                if(t > time) continue;
                if(dp[intial_city][time-t] != INT_MAX) {
                    dp[dest_city][time] = min(dp[dest_city][time], dp[intial_city][time-t]+passingFees[dest_city]);
                }
                if(dp[dest_city][time-t] != INT_MAX) {
                    dp[intial_city][time] = min(dp[intial_city][time], dp[dest_city][time-t]+passingFees[intial_city]);
                }
            }
        }
        int ans = INT_MAX;
        for(i=0;i<=maxTime;++i){
            ans = min(ans, dp[n-1][i]);
        }
        return ans==INT_MAX ? -1 : ans ;
    }
};