class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int x: nums){
            mp[x]++;
        }
        unordered_map<int,int> freq;
        for(auto x : mp){
            freq[x.second]++;
        }
        for(auto x: nums){   // to return firts ele that exists in the array first and has unique frequency
            if(freq[mp[x]] == 1) return x ; 
        }
        return -1;
    }
};