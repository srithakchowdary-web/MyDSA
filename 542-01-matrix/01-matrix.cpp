class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m= mat.size();
        int n= mat[0].size();
        int i,j;
        vector<vector<int>> ans(m,vector<int>(n));
        queue<pair<pair<int,int>, int>> q;
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                if(mat[i][j]==0) {
                    q.push({{i,j},0});
                    ans[i][j]=0;
                }
                else ans[i][j]=-1;
            }
        }
        while(!q.empty()){
            auto [pos,dist] = q.front();
            q.pop();
            int r= pos.first;
            int c=pos.second;
            if(r > 0  && ans[r-1][c]==-1){
                q.push({{r-1,c},dist+1});
                ans[r-1][c] = dist+1;
            }
            if(r < m-1 && ans[r+1][c]==-1){
                q.push({{r+1,c},dist+1});
                ans[r+1][c] = dist+1;
            }
            if(c > 0  && ans[r ][c-1]==-1){
                q.push({{r,c-1},dist+1});
                ans[r ][c-1] = dist+1;
            }
            if(c < n-1  && ans[r][c+1]==-1){
                q.push({{r ,c+1},dist+1});
                ans[r][c+1] = dist+1;
            }
        }
        return ans;
    }
};