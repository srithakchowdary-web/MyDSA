class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1, high=0;
        for(int x: candies){
            //sum += x;
            if(x > high) high = x;
        }
        int ans =0;
        while(low <= high){
            int mid = low +(high-low) / 2 ;
            long long val = 0 ;
            for(int x : candies){
                val += x/mid;
            }
            if(val >= k)  {
                ans = mid;
                low = mid+1 ;
            }
            else high = mid-1 ;
        }
        return ans;
    }
};