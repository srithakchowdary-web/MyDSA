#include<cmath>
#include<climits>
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i=0 ;
        long long j = sqrt(INT_MAX);
        while(i <= j){
            long long square =  i*i + j*j;
            //int b = j*j ;
            if(square == c) return true;
            if(square > c) --j;
            else ++i;
        }
        return false;
    }
};