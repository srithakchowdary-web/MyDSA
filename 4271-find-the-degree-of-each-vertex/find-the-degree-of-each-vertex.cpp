class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size(), i,j;
        vector<int> ans (n);
        for(i=0;i<n;++i){
            int count =0;
            for(j=0;j<n;++j){
                if(matrix[i][j]==1) count += 1;
            }
            ans[i]=count;
        }
        return ans;
    }
};