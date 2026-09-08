class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, pair<int, pair<int,int>>> mp;
        int count = 0;
        for(int i=0;i<nums.size();++i){
            if(mp.find(nums[i]) == mp.end()){
                //mp.insert(nums[i]);
                int key = nums[i];
                mp[key].first++ ;
                mp[key].second.first = i;
                mp[key].second.second = i;
            }
            else{
                mp[nums[i]].first ++ ;
                mp[nums[i]].second.second = i;
            }
        }
        for(auto x : mp){
            int r = x.second.second.second;
            int l = x.second.second.first;
            int freq = x.second.first;
            if(freq == (r-l+1)) ++count;
        }
        return count;
    }
};