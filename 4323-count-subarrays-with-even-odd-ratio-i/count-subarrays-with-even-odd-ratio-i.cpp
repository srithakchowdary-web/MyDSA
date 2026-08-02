class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int count=0;
        int odd=0,even=0;
        int i=0,j,n =nums.size();
        j = 0;
        vector<int> prex(n+1,0);
        vector<int> prey(n+1,0);
        for(i=0;i<n;++i){
            if(nums[i]%2==0) even++;
            else odd++;
            prex[i+1]=even;
            prey[i+1]=odd;
        }
        for(i=0;i<n;++i){
            for(j=0;j<n;++j){
                int x = prex[j + 1] - prex[i];
                int y = prey[j + 1] - prey[i];
                if (y > 0 && x * b <= a * y)  count+=1;
            }
        }
        return count;
    }
};