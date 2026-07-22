class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if( k == 1) return true;
        int n,i=0,j,l;
        n= nums.size();

        while(i <= n-2*k){
            int m =  i+k-1  ;
            bool broke = false;
            for(j =i+1 ; j<=m; ++j){
                if(nums[j] <= nums[j-1]){
                    i=j;
                    broke = true;
                    break;
                
                }
            }
            if(!broke && j>m) {
                for(l =i+k+1;l<= m+k;++l){
                    if(nums[l] <= nums[l-1]){
                         i = l-k;
                         broke = true;
                         break;
                    }
                }
                if(!broke  && l > m+k) return true;
            }
           // if(!broke)
        }
        return false;
    }
};