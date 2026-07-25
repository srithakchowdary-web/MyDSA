class Solution {
public:
    int maxProduct(int n) {
        //const long long MOD = 1e9+7;
        priority_queue<int, vector<int>, greater<int>> pq;
        while(n>0){
            pq.push(n%10);
            n /= 10;
            while(pq.size() > 2) pq.pop();
        }
        int ans = pq.top();
        pq.pop();
        return ans*pq.top();
    }
};