class Solution {
public:
    int solve(vector<int>& costs, vector<int>& days, vector<int>& dp, int idx, int n){
        if(idx >= n) return 0;
        if(dp[idx] != INT_MAX)  return dp[idx];
        
        int one_pass = costs[0]+solve(costs,days, dp,idx+1,n);
        int next = idx;
        while(next < n  && days[next] < days[idx]+7)  ++next;
        int seven_pass = costs[1] + solve(costs,days, dp,next,n);
        next = idx;
        while(next < n  && days[next] < days[idx]+30)  ++next;
        int thirty_pass = costs[2] + solve(costs,days, dp,next,n);
        return dp[idx] = min(one_pass, min(seven_pass, thirty_pass));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, INT_MAX);
        return solve(costs,days,dp,0, n);
    }
};