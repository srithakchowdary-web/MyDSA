class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m= grid.size(),n=grid[0].size(),s,i,j;
        s = m*n;
        vector<int> v;
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                v.push_back(grid[i][j]);
            }
        }
        vector<int> temp(s);
        for(i=0;i<s;++i){
            temp[(i+k)%s] = v[i];
        }
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                grid[i][j] =  temp[i*n+j];
            }
        }
        return grid;
    }
};