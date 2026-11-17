class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int i, rem=1, n= digits.size();
        for(i=n-1;i>=0;--i){
            int v = digits[i]+rem;
            if(v > 9){
                rem = 1;
                ans.push_back(v%10);
            }
            else{
                rem = 0;
                ans.push_back(v);
            }
        }
        if(rem > 0) ans.push_back(rem);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};