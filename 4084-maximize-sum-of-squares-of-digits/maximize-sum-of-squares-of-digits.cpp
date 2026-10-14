class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9*num) return "";
        string ans (num,'0');
        int i=0;
        while(sum >= 9){
            ans[i] = '9'; //adding as more no.of 9's as possible to maximize the result
            ++i;
            sum -= 9;
        }
        if(sum > 0) ans[i]='0'+sum ;
        return ans;
    }
};