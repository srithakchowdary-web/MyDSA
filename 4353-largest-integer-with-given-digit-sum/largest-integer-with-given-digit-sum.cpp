class Solution {
public:
    int largestInteger(int n, int s) {
        int max_sum = 9*n ;
        if(s > max_sum) return -1;
        if(s==0) return 0;
        int num=0;
        while(n > 0){
            num = num*10+9 ;
            --n;
        }
        while(num > 0){
            int sum =0;
            int x = num;
            while(x > 0){
                sum += x%10;
                x /= 10;
            }
            if(sum == s) return num;
            if(s > sum) return -1;
            
            int dif = sum - s ;
            num -= dif ;
            
        }
        return -1;
    }
};