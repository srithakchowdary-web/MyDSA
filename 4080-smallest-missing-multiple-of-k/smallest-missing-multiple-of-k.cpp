class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, unordered_set<int>> mp;
        int i, n=nums.size();
        for(i=0;i<n;++i){
            if(nums[i]%k  == 0){
                mp[k].insert(nums[i]);
            }
        }
        i =1;
        for(int x : mp[k]){
            if(mp[k].count(k*i)) ++i;
            else return k*i ;
        }
        return k*i;
    }
};