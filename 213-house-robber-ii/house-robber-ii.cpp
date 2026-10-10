class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int i, int n){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i]+solve(nums,dp, i+2, n);
        int skip = solve(nums,dp,i+1,n);
        return dp[i] = max(take,skip);
    }
    int solve1(vector<int>& nums, vector<int>& dp1, int i, int n){
        if(i >= n) return 0;
        if(dp1[i] != -1) return dp1[i];
        int take = nums[i]+solve(nums,dp1, i+2, n);
        int skip = solve(nums,dp1,i+1,n);
        return dp1[i] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        //if(n)
        int n= nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp(n-1,-1);
        return max(solve(nums,dp,0,n-1), solve1(nums,dp1,1,n));
    }
};