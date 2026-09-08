class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //apply binary serach; if ground is going up, move forward
        int n = nums.size();
        if(n==1) return 0;
        int lt = 0, rt = n-1;
        while(lt < rt){
            int mid = lt + (rt-lt) / 2 ;
            if(nums[mid] < nums[mid+1]){
                lt = mid+1;
            }
            else rt = mid;
        }
        return lt;
    }
};