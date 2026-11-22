class Solution {
public:
    int solve(vector<int>& dp, vector<int>& nums, int target, int v, int n){
        if(v == target) return 1;
        if( v > target) return 0;
        if(dp[v] != -1) return dp[v];
        int take=0 ;
        for(int i=0;i<n;++i){
            if(nums[i]+v <= target) take += solve(dp, nums, target, v+nums[i], n);
        }
        return dp[v]=take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int i, ans, n=nums.size();
        vector<int> dp(target+1, -1);
        
        return solve(dp, nums, target, 0, n);
    }
};