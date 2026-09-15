class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int i,n=nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(i=0;i<n;++i){
            pq.push(nums[i]);
        }
        while(k > 0){
            int v = pq.top();
            pq.pop();
            pq.push(v+1);
            --k;
        }
        long long ans = 1;
        int MOD = 1e9+7 ;
        while(!pq.empty()){
           ans = (ans*pq.top()) % MOD;
           pq.pop();
        }
        return ans;
    }
};