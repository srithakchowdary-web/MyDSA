class Solution {
public:
    bool solve(vector<int>& nums, vector<int>& dp, int n, int i){
        if (i >= n-1) return true;
        if(dp[i] != -1) return dp[i];
        for(int k =1; k<= nums[i]; ++k){
            bool reach = solve(nums,dp,n,i+k);
            if(reach) return dp[i] = true;
        }
        return  dp[i] =  false ;
    }
    bool canJump(vector<int>& nums) {
        //dp similar to take/skip
        vector<int> dp(nums.size(),-1);
        //int a = solve(nums,dp,n,0);
        return solve(nums,dp,nums.size(),0) ;
    }
};