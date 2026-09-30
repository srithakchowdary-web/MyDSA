class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> mp;
        for(char c : s){
            mp[c] ++ ;
        }
        int i,n=s.size();
        for(i=0;i<n;++i){
            if(mp[s[i]] == 1) return i;
        }
        return -1;
    }
};