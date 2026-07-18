class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int  n;
        n = nums.size();
        int i=n-3, j=n-2, k=n-1;
        while(i >= 0){
            int sum = nums[i]+nums[j];
            if(sum > nums[k]) return sum+nums[k];
            --i;
            --j;
            --k;
            
        }
        return 0;
    }
};