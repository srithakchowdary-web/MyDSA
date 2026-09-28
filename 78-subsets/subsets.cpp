class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void solve(vector<int>& nums, int idx){
        ans.push_back(curr);
        for(int i=idx; i<nums.size(); ++i){
            curr.push_back(nums[i]);
            solve(nums, i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //vector<int> curr; 
        solve(nums,0);
        return ans;
    }
};