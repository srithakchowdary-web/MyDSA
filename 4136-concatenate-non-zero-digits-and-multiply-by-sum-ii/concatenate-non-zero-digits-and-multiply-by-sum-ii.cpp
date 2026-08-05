class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1e9+7;
        //calc powers so it does not overflow when u actualy doing or multiplying that
        int i,n,m=s.size();
        n = queries.size();
        vector<int> ans;
        vector<long long> pre_sum(m+1,0);
        vector<long long> p_str(m+1,0);
        vector<int> cnt(m + 1, 0);
        vector<long long> power(m+1,1);
        for(i=1;i<=m;++i){
            power[i]=power[i-1]*10 %  MOD ;
        }
        //prefix sum
        for(i=1;i<=m;++i){
            pre_sum[i]=pre_sum[i-1]+(s[i-1]-'0');
        }
        //prefix string
        for(i = 1; i <= m; ++i) {
            if(s[i - 1] != '0') {
                p_str[i] = (p_str[i - 1] * 10 + (s[i - 1] - '0')) % MOD;
                cnt[i] = cnt[i - 1] + 1;
            }
            else {
                p_str[i] = p_str[i - 1];
                cnt[i] = cnt[i - 1];
            }
        }
        for(i=0;i<n;++i ){
            int lt = queries[i][0];
            int rt = queries[i][1];
            int sum = pre_sum[rt+1]-pre_sum[lt];
            int dif = cnt[rt+1]-cnt[lt];
            long long n1 =p_str[lt]%MOD;
            long long n2 =  p_str[rt+1] %MOD;
            
            n1 = (n1 * power[dif]) % MOD;
            ans.push_back((((n2 - n1 +MOD) % MOD) * sum) % MOD);
        }
        return ans;
    }
};