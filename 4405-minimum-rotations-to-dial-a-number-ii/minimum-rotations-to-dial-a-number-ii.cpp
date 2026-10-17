class Solution {
public:
    int minRotations(int n, string s) {
        int sum=0, curr=0;
        for(char c : s){
            int idx = c-'0' ;
            int v = min(((10-curr)+idx), (curr+(10-idx)));
            sum += min(abs(idx-curr), v);
            curr = idx;
        }
        int ans = sum, prev=0;
        for(int k=0;k < n-1; ++k){
            int d1 = abs(prev - (s[k] - '0'));
            int dist_k = min(d1, 10 - d1);

            int d2 = abs(prev - (s[n - 1] - '0'));
            int dist_last = min(d2, 10 - d2);
            int val = sum - dist_k + dist_last ;
            ans = min(ans,val);
            prev = s[k]-'0';
        }
        return ans;
    }
};