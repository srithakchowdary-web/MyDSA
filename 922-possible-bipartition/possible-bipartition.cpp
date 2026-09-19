class Solution {
public:
    bool solve(int src, vector<int>& color, vector<vector<int>>& graph){
        queue<int> q;
        q.push(src);
        color[src]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int x: graph[node]){
                if(color[x] ==  -1){
                    if(color[node]==0)  color[x]=1;
                    else color[x]=0;
                    q.push(x);
                }
                else if(color[x] == color[node])  return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        int m = dislikes.size(),i;
        for(i=0;i<m;++i){
            //undirected relation coz they have to be in dif groups, if one ele dislikes the other
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> color(n+1, -1);
        for(i=1;i<=n;++i){
            if(color[i] == -1){
                if(!solve(i, color, graph))  return false;
            }
        }
        return true;
    }
};