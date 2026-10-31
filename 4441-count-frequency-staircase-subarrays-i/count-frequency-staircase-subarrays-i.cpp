class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int i, j, n = nums.size();
        int ans = n;

        for(i = 0; i < n; ++i) {
            unordered_map<int, int> mp;
            vector<int> order;

            mp[nums[i]]++;
            order.push_back(nums[i]); 
            for(j = i + 1; j < n; ++j) {
                if(mp.find(nums[j]) == mp.end()) {
                    order.push_back(nums[j]);
                }
                mp[nums[j]]++;
                int s = mp.size();
                int val = 1;
                int num = 0; 
                for(auto x : order) {
                    if(mp[x] == val) {
                        ++num;
                        ++val;
                    }
                    else {
                        break;
                    }
                } 
                if(num == s)
                    ans++;
            }
        }
        return ans;
    }
};