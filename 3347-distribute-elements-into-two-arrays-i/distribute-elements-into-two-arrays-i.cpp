class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a1;
        vector<int> a2;
        int i,n=nums.size();
        a1.push_back(nums[0]);
        a2.push_back( nums[1]);
        int last_ele1 = nums[0];
        int last_ele2 = nums[1];
        for(i=2;i<n;++i){
            if(last_ele1 > last_ele2){
                a1.push_back(nums[i]);
                last_ele1 = nums[i];
            }
            else{
                a2.push_back(nums[i]);
                last_ele2 = nums[i];
            }
        }
        a1.insert(a1.end(),a2.begin(),a2.end());
        return a1;
        
    }
};