class Solution {
public:
    //int ans =0;
    int solve(vector<int>& nums, vector<int>& dp, int i, int n){
        if(i >= n )  return 0;  // no houses left
        if(dp[i] != -1)  return dp[i];
        //take the curr aand skip the next
        int take = nums[i]+solve(nums,dp,i+2, n);
        //skip
        int skip = solve(nums,dp,i+1,n);
        return dp[i] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums,dp,0, nums.size());
    }
};