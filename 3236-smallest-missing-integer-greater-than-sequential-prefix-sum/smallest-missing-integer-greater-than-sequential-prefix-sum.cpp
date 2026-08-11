class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int i,n=nums.size();
        for(i=1;i<n;++i){
            if(nums[i]==nums[i-1]+1){
                sum += nums[i];
            }
            else break;
        }
        unordered_set<int> mp(nums.begin(), nums.end());

        while(sum <= 2501){
            if(!mp.count(sum)) return sum;
            sum += 1;
        }
        return 0;
    }
};