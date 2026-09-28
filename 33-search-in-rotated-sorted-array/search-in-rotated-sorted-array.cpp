class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, rt=nums.size()-1;
        while(l <= rt){
            int mid = l +(rt-l)/2 ;
            if(nums[mid]==target) return mid;
            if(nums[mid] > nums[rt]){
                if(target >= nums[l]  && target < nums[mid]) rt = mid-1;
                else l = mid+1;
            }
            else{
               if(nums[mid]<target && target <= nums[rt]) l = mid+1;
               else rt= mid-1;
            }
        }
        return -1;
    }
};