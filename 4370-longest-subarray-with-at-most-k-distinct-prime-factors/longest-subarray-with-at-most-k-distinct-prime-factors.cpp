class Solution {
public:
    unordered_map<int, unordered_set<int>> mp;

    void primefactors(vector<int>& nums){
      for(int i = 0; i < nums.size(); ++i){

        if(mp.count(nums[i]))
            continue;

        int n = nums[i], k = 2;

        while(n > 1){
            if(n % k == 0){
                mp[nums[i]].insert(k);
                n /= k;
            }
            else {
                ++k;
            }
        }
      }
    }

    int longestSubarray(vector<int>& nums, int k) {

        primefactors(nums);

        unordered_map<int,int> mp1;

        int i, j, ans = 0;
        int n = nums.size();

        // Find first invalid element
        for(i = 0; i < n; ++i){

            for(auto x : mp[nums[i]])
                mp1[x]++;

            if(mp1.size() > k){

                // Remove the invalid element
                for(auto x : mp[nums[i]]){
                    mp1[x]--;

                    if(mp1[x] == 0)
                        mp1.erase(x);
                }

                j = i - 1;
                break;
            }
        }

        if(i == n)
            return n;

        ans = j + 1;

        for(i = 1; i < n; ++i){

            // Remove nums[i-1] ONLY if it belongs to [i-1 ... j]
            if(i - 1 <= j){
                for(auto x : mp[nums[i-1]]){
                    mp1[x]--;

                    if(mp1[x] == 0)
                        mp1.erase(x);
                }
            }

            // If window became empty
            if(j < i - 1)
                j = i - 1;

            while(j + 1 < n){

                ++j;

                for(auto x : mp[nums[j]])
                    mp1[x]++;

                if(mp1.size() > k){

                    // Undo nums[j]
                    for(auto x : mp[nums[j]]){
                        mp1[x]--;

                        if(mp1[x] == 0)
                            mp1.erase(x);
                    }

                    --j;
                    break;
                }
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};