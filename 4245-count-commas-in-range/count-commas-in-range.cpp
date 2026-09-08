class Solution {
public:
    int countCommas(int n) {
        if(n < 1000) return 0;
        // no commas needed for a value 1 to 999, we gitta find the no.of commas to write from 1 to n
        return n - 999;
    }
};