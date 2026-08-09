class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        double ans=0;
        sort(prices.begin(),prices.end(), greater<int> ());
        sort(discounts.begin(),discounts.end(), greater<int> ());
        int m= min(prices.size(), discounts.size());
        for(int i=0;i<m;++i){
            int d = discounts[i];
            ans += prices[i]*(100.0-d)/100.0 ;
        }
        for(int i=m;i<prices.size(); ++i){
            ans += prices[i];
        }
        return ans;
    }
};