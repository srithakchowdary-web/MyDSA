class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int i,n;
        n = nums.size();
        if(n==1) return 1;
        if(n==2) return 2;
        int minpos, maxpos;
        int maxv=INT_MIN, minv = INT_MAX;
        for(i=0;i<n;++i){
            if(nums[i] < minv) {
                minv = nums[i];
                minpos = i;
            }
            if(nums[i] > maxv) { 
                maxpos=i;
                maxv=nums[i];
            }
        }
        int count =0;
        //try deletion of min ele first then max ele
        int mindif = min(minpos+1, n-minpos);
        int maxdif = min(maxpos+1, abs(minpos-maxpos));
        maxdif = min(maxdif, n-maxpos);
        count += mindif+maxdif ;
        int ans = count;
        count =0;
        //deletion of max ele forst then min ele
        maxdif= min(maxpos+1, n-maxpos);
        mindif = min(minpos+1, abs(minpos-maxpos));
        mindif = min(mindif, n-minpos);
        count += mindif+maxdif;
        return min(ans,count);
    }
};