class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        // idea: find the first pos at which the ele is decreasing; incraese the curr ele or decrease the prev ele; if any of this results in non-decreasing array; return true.
        int i, idx=-1, n=nums.size();
        for(i=1;i<n;++i){
            if(nums[i] < nums[i-1]){
                idx = i;
                break;
            }
        }
        if(idx == -1) return true;
        bool prev=true, curr=true;
        int current = nums[idx];
        int previous = nums[idx-1];
        //change the previous ele nums[i-1]=nums[i]
        nums[idx-1] = nums[idx];
        if(idx - 2 >= 0 && nums[idx-2] > nums[idx-1]) prev = false;  // we alos need the prev of prev one coz we anyways checking teh coming onees
        for(i=idx+1;i<n;++i){
            if(nums[i] <  nums[i-1]){
                prev = false;
                break;
            }
        }
        nums[idx-1] = previous;
        //change the curr ele
        nums[idx]= nums[idx-1];
        for(i=idx+1; i<n;++i){
            if(nums[i] < nums[i-1]){
                curr = false;
                break;
            }
        }
        return (prev || curr);
    }
};