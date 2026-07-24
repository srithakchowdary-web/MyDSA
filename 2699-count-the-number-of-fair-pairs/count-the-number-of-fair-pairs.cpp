class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long  count1=0, count2=0;
        int i,j,n;
        n = nums.size();
        sort(nums.begin(),nums.end());
        i=0;
        j = n-1;
        while(i < j){
            // for finding upper point
            int sum = nums[i]+nums[j];
            if(sum <= upper){
                count1 += (j-i);
                ++i; 
            }
            else --j;
        }
        i=0;
        j=n-1;
        while(i < j){
            // for finding lower point
            int sum = nums[i]+nums[j];
            if(sum < lower){
                count2 += (j-i);
                ++i;
                
            }
            else --j;
        }
        return count1 - count2 ;
    }
};// approach : <=upper - <lower