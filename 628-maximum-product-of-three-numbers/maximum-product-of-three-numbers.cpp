class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int i,n = nums.size(),c=0,zero=0;
        if(n==3) return nums[0]*nums[1]*nums[2];
        for(i=n-3;i<n;++i){
            if(nums[i]<0) c++;
            if(nums[i]==0)  zero+=1;
        }
        if((zero==0 && c==2) || (zero==2 && c==0) || (zero==1 && c==1) || (zero==1 && c==0)){
            return nums[n-1]*nums[0]*nums[1];
        }
        if((zero==0 && c==3)){
            return nums[n-3]*nums[n-2]*nums[n-1];
        }
        if((zero==0 && c==1) ){
            return nums[0]*nums[1]*nums[n-1];
        }
        if(zero == 0 && c == 0){
            int ans2 = nums[n-1] * nums[n-2] * nums[n-3];

            if(nums[0] < 0 && nums[1] < 0){
                int ans1 = nums[0] * nums[1] * nums[n-1];
                return max(ans1, ans2);
            }

            return ans2;
        }
        return 0;
    }
};