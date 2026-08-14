class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int i, n=grid.size();
        if(grid[0][0] ==1|| grid[n-1][n-1]==1)  return -1;
        if(n==1 && grid[0][0]==0) return 1;
        queue<pair<pair<int,int>, int>> q;
        q.push({{0,0},1});
        grid[0][0]=1;
        while(!q.empty()){
            auto[pos,dist] = q.front();
            q.pop();
            int r=pos.first;
            int c = pos.second ;
            if(r==n-1 && c==n-1)  return dist;
            if(r>0  && grid[r-1][c]==0){ //up
                q.push({{r-1,c},dist+1});
                grid[r-1][c]=1;
            }
            if(r < n-1  && grid[r+1][c]==0){ //bottom
                q.push({{r+1,c},dist+1});
                grid[r+1][c]=1;
            }
            if(c >0  && grid[r][c-1]==0){ //left
                q.push({{r,c-1},dist+1});
                grid[r][c-1]=1;
            }
            if(c  < n-1  && grid[r][c+1]==0){ //right
                q.push({{r,c+1},dist+1});
                grid[r][c+1]=1;
            }
            if(r>0 && c < n-1  && grid[r-1][c+1]==0){ //upper right
                q.push({{r-1,c+1},dist+1});
                grid[r-1][c+1]=1;
            }
            if(r>0 && c>0 && grid[r-1][c-1]==0){ //upper left
                q.push({{r-1,c-1},dist+1});
                grid[r-1][c-1]=1;
            }
            if(r< n-1 && c > 0  && grid[r+1][c-1]==0){ //bottom left
                q.push({{r+1,c-1},dist+1});
                grid[r+1][c-1]=1;
            }
            if(r< n-1 && c < n-1  && grid[r+1][c+1]==0){ //bottom rt
                q.push({{r+1,c+1},dist+1});
                grid[r+1][c+1]=1;
            }
        }
        return -1;
    }
};