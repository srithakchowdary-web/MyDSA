class Solution {
public:
    int solve(int num, int sum){
        //int n = num;
        while(num > 0){
            sum += num % 10 ;
            num /= 10;
        }
        if(sum > 9){
            return  solve(sum, 0);
        }
        else return sum;
    }
    int addDigits(int num) {
        if(num == 0) return 0;
        return solve(num,0);
    }
};