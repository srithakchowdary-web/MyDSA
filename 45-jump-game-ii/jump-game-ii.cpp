class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int idx, int n){
        if(idx >= n-1) return 0;
        if(dp[idx] != -1)  return dp[idx];
        int ans = INT_MAX;
        for(int i=1;i<=nums[idx];++i){
            int steps = solve(nums,dp,idx+i, n);
            if(steps != INT_MAX) ans = min(ans, 1+steps);
        }
        return dp[idx]=ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums, dp, 0,n);
    }
};