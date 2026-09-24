class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1, high=10000000, i;
        int  n = dist.size();
        //for(int x : dist) high = max(high, x);
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high-low) / 2;
            double val = 0;
            for(i=0;i<n;++i){
                if(i  == n-1){
                    val += (double) dist[i]/mid ;
                }
                else{
                    int v= dist[i]/mid;
                    val += v;
                    if(dist[i]%mid != 0) val += 1;
                }
                if(val > hour) break;
            }
            if(val <= hour)  {
                ans = min(ans, mid);
                high = mid-1;
            }
            else low = mid+1 ;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};