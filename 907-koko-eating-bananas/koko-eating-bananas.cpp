class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mini =1, maxi=-1;
        int i,n,k=INT_MAX;
        n= piles.size();
        for(i=0;i<n;++i){
            maxi = max(maxi, piles[i]);
        }
        while(mini <= maxi){
            int mid = (mini+maxi)/2 ;
            long long hours = 0;
            bool possible = false;
            for(i=0;i<n;++i){
                if(hours > h)  break;
                int d = piles[i]/mid ;
                if(piles[i]%mid  == 0)  hours += d;
                else hours = hours+d+1 ;
            }
            if(hours <= h)  possible = true;
            if(possible)  {
                maxi = mid-1;
                k = min(k,mid);
            }
            else mini = mid+1 ;
        }
        return k;
    }
};