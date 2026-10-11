class Solution {
public:
    int solve(unordered_map<int,int>& mp, vector<int>& dp, int idx, int mx){
        if(idx > mx) return 0;
        if(dp[idx] != -1) return dp[idx];
        int val = mp.count(idx) ? idx*mp[idx] : 0;
        int take = val + solve(mp,dp,idx+2,mx);
        int skip = solve(mp,dp,idx+1,mx);
        return dp[idx] = max(take,skip);
    }
    int deleteAndEarn(vector<int>& nums) {
        //dp for all numbers possible from 1 to max of nums;
        //you are trying same take and skip not nums but on the val from 1 to max val of nums
        unordered_map<int,int> mp;
        int  mx=0;
        for(int x : nums){
            mp[x]++;
            mx = max(mx, x);
        }
        vector<int> dp(mx+1,-1);
        return solve(mp,dp,0,mx);
    }
};