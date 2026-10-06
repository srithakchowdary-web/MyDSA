class Solution {
public:
    string reduce(string s){
        int i=1,c=1;
        int n = s.size();
        string val;
        while(i < n){ 
            if(s[i] == s[i-1]){
                ++c;
            }
            else {
                val += to_string(c) + s[i-1];
                c = 1;
            }
            ++i;
        }
        val += to_string(c) + s[i-1];
        return val;
    }
    string sol(int i, int n , string ans){
        if(i > n)  return ans;
        ans = reduce(ans);
        return sol(i+1,n,ans);
    }
    string countAndSay(int n) {
        if(n==1) return "1";
        return sol(2,n,"1");
    }
};