class Solution {
public:
    int trailingZeroes(int n) {
        if(n < 5) return 0;
        //aptitude: no.of zeros depends on 2 and 5, no.of 0's = min(no.of 2's, no.of 5's)
        int  i, fives=0 ;
        //but for an n - no.of 5's are always < no.of 2's
        for(i=5;i<=n;++i){
            int x= i;
            while(x%5 == 0){
                fives += 1;
                x /= 5;
            }
        }
        return fives;
    }
};