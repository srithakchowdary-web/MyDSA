class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        // BFS/DFS APPROACH,  count the communicating servers only once 
        // count no.of 1's (ones) and check for ecah 1 if there are 1's in same col or row, if not, subtract from ones
        int i,j,n,m;
        m = grid.size();
        n= grid[0].size();
        stack<pair<int,int>> st;
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                if(grid[i][j]==1) st.push({i,j});
            }
        }
        int ans=0;
        while(st.size() > 0){
            auto [row, col] = st.top();
            st.pop();
            bool exist = false;
            for(j=0;j<n;++j){
                if(j != col && grid[row][j]==1) {
                    exist = true;
                    break;
                }
            }
            for(i=0;i<m;++i){
                if(i != row && grid[i][col] == 1){
                    exist = true;
                }
            }
            if(exist) ans += 1;
        }
        return ans;
    }
};