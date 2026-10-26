class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long sum = 0;
        int i, n= nums.size();
        priority_queue<long long> pq;
        // in pq we r only pushing the values that are improved, if not imroved we are not adding them to pq so first we sum up the values in nums and add the improvemnts to pq and we will add those to sum again, such sum is maximized not graeter than k ele r rearraned, moreover we r doing it in order.
        for(i=0;i<n;++i){
            sum += nums[i];
            string s = to_string(nums[i]);
            string num=s;
            sort(num.begin(), num.end(), greater<char>());
            if(num == s) continue;
            pq.push(stoll(num)- nums[i]);
            //mp[i]++;
        }
        //long long sum =0;
        while(!pq.empty() && k > 0){
            sum += pq.top();
            pq.pop();
            --k;
        }
        return sum;

    }
};