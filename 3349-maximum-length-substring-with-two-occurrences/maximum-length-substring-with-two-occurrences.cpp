class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i, n=s.length(),j=0;
        int ans = -1;
        unordered_map<char,int> mp;
        for(i=0;i<n;++i){
            mp[s[i]]++;
            while(mp[s[i]] > 2){
                mp[s[j]]-- ;
                j += 1;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
    
};