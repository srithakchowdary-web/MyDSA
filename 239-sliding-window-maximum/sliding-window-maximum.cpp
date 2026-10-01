class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int i,n= nums.size();
        deque<int> dq;
        for(i=0;i<k;++i){
            while(dq.size() > 0  && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for(i=k;i<n;++i){
            while(dq.size()> 0  && dq.front() <= i-k){
                dq.pop_front();
            }
            while(!dq.empty()  && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};