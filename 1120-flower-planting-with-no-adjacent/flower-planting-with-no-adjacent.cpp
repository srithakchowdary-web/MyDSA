class Solution {
public:
    void solve(int src, vector<int>& colors, vector<vector<int>>& graph){
        queue<int> q;
        q.push(src);
        colors[src]=1;
        // a few changes to the actual biparitite coz u cant assign more than val 4 to any node
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int x : graph[node]){
                if(colors[x] == -1){
                    bool used[5] = {false};
                    for(int neigh : graph[x]){
                        if(colors[neigh] != -1) used[colors[neigh]]=true;
                    }
                    for(int v =1;v<=4;++v){
                        if(!used[v]){
                            colors[x]=v;
                            break;
                        }
                    }
                    q.push(x);
                }
                
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n+1);
        int m = paths.size();
        for(int i=0;i<m;++i){
            graph[paths[i][0]].push_back(paths[i][1]);
            graph[paths[i][1]].push_back(paths[i][0]);
        }
        vector<int> colors(n+1, -1);
        for(int i=1;i<=n;++i){
            if(colors[i]==-1){
                solve(i, colors, graph);
            }
        }
        return {colors.begin()+1, colors.end()};
    }
};