class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int count =0,n=nums.size();
        int lt =0, rt=n/2 ;
        long long sumf=0, suml=0;
        int  i ;
        for(i=0;i<rt;++i){
            sumf += nums[i];
        }
        for(i=rt;i<n;++i){
            suml += nums[i];
        }
        while(lt < n){
            if(sumf > suml) count += 1;
            sumf = sumf-nums[lt]+nums[rt];
            suml = suml-nums[rt]+nums[lt];
            ++lt;
            ++rt;
            if(rt==n) rt=0;
        }
        return count;
    }
};