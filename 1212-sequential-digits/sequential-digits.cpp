class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v = {12,23,34,45,56,67,78,89,123,234,1234,345,2345,12345,456,3456,23456,123456,567,4567,34567,234567,1234567,678,5678,45678,345678,2345678,12345678,789,6789,56789,456789,3456789,23456789,123456789};
        vector<int> ans;
        for(int i=0;i<v.size();++i){
            if(v[i] >= low && v[i] <= high){
                ans.push_back(v[i]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};