#include<cmath>
class Solution {
public:
    long long power(long long x, long long y) {
        long long MOD = 1e9 + 7;
        long long v = 1;

        while(y > 0) {
            if(y % 2 == 1)
                v = (v * x) % MOD;

            x = (x * x) % MOD;
            y /= 2;
        }

        return v;
    }

    int sumDecoded(vector<long long>& nums) {
        int MOD = 1e9+7;
        int ans = 0;
        for(int i=0;i<nums.size();++i) {
            int width = nums[i]%10;
            long long dec = nums[i]/10 ;
            long long val = dec;
            int n=0;
            while(val > 0){
                val/=10;
                ++n;
            }
            val = dec;
            int  d= n - width;
            long long p = pow(10,d);
            long long x = val/p;
            int y = dec%p ;
            // xpower y can be huge so use a functionto keep it limited
            ans = (ans + power(x,y)) % MOD;
        }
        return ans;
    }
};