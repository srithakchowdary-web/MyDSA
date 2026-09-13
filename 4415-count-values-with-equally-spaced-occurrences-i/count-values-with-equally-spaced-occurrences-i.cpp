class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size(), ans=0;
        for(int i=0;i<n;++i){
            mp[nums[i]].push_back(i);
        }
        for(auto x : mp) {
            if(x.second.size() == 3) {
                int m = x.second.size();
                int dif = x.second[1] - x.second[0];

                for(int i = 2; i < m; ++i) {
                    if(x.second[i] - x.second[i-1] == dif)
                        ans++;
                }
            }
        }
        return ans;
    }
};