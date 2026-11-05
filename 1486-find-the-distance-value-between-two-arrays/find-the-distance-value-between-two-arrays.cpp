class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // o(n2) -- easy
        int ans=0;
        for(int x : arr1){
            bool condition=true;
            for(int y : arr2){
                if(abs(x-y) <= d) {
                    condition = false;
                    break;
                }
            }
            if(condition) ans ++ ;
        }
        return ans;
    }
};