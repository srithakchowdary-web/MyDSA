class Solution {
public:
    int minDeletions(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        int i ,n=nums.size();
        int count=0;
        for(i=1; i<n;++i){
            if(nums[i]==nums[i-1])  count += 1;
        }
        return count;
    }
};