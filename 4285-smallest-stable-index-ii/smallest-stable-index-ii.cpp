class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;
        int mini = INT_MAX, maxi = INT_MIN;
        int i, n=nums.size();
        //min
        for(i=n-1;i>=0;--i){
            if(nums[i] < mini) {
                mp[i].push_back(nums[i]);
                mini = nums[i];
            }
            else mp[i].push_back(mini);
        }
        //max
        for(i=0;i<n;++i){
            if(nums[i] > maxi){
                mp[i].push_back(nums[i]);
                maxi=  nums[i];
            }
            else mp[i].push_back(maxi);
        }
         
        for(i=0;i<n;++i){
            int dif = mp[i][1]-mp[i][0] ;
            if(dif <= k) return i;
        }
        return -1;

    }
};