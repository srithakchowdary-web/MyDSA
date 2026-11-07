class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x; // trivial cases
        int high = x/2;
        int low =0;
        while(low <= high){
            long long mid = low+(high-low) / 2;
            if(mid*mid  == x) return mid;
            else if(mid*mid  > x) high = mid-1;
            else low = mid+1 ;
        }
        return high;
    }
};
