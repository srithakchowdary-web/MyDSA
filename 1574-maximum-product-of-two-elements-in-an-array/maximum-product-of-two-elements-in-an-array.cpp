class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i, ans=0,pos,n,ans1=0;
        n = nums.size();
        for(i=0;i<n;++i){
            if(nums[i] > ans){
                ans = nums[i];
                pos = i;
            }
        }
        for(i=0;i<n;++i){
            if(i!=pos  &&  nums[i] > ans1){
                ans1 = nums[i];
            }
        }
        return (ans-1)*(ans1-1);
    }
};