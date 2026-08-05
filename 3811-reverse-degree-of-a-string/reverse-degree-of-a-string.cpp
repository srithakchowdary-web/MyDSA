class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.size();++i){
            int v = s[i]-'a';
            ans = ans+(26-v)*(i+1);
        }
        return ans;
    }
};