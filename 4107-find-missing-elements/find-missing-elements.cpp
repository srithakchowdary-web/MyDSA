class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini=INT_MAX, maxi= INT_MIN;
        unordered_map<int,int> mp;
        for(int x : nums){
            mp[x]++;
            mini = min(mini,x);
            maxi = max(maxi,x);
        }
        vector<int> ans;
        for(int i=mini;i<=maxi;++i){
            if(!mp.count(i)) ans.push_back(i);
        }
        return ans;
    }
};