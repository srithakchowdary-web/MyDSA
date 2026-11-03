class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if(value == 1) return -1;
        long long ans;
        long long rt = (long long)n - index - 1;
        if(value%2 == 0) {
            int v = value/2 - 1;
            if(v >= index)  {
                ans = (long long) value + rt*2 ;
                //return ans;
            }
            else return -1;
        }
        else{
            int x=value;
            //find the smallest digit that divides val
            for(long long i=3; i*i <=  value; i+=2){
                if(value%i == 0) {
                    x=i;
                    break;
                }
            }
            int prev = value - x;
            //int nxt = value+x;
            int v = prev/2;
            if(v >= index ){
                if(rt==0) ans = value;
                else ans = (long long) value + x + (rt-1)*2 ;
            }
            else return -1;
        }
        return ans;
    }
};