class Solution {
public:
    bool bfs(int src, vector<int>& color, vector<vector<int>>& graph){
        queue<int> q;
        q.push(src);
        color[src]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int x : graph[node]){
                if(color[x] == -1){
                    if(color[node] == 0) color[x]=1;
                    else color[x]=0;
                    q.push(x);
                }
                else if(color[x] == color[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(), i;
        vector<int> color(n,-1);
        for(i=0;i<n;++i){
            if(color[i] == -1){
                if(!bfs(i, color, graph)) return false;
            }
        }
        return true;
    }
};