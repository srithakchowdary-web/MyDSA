class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //jiska edges and no.of vertices will be n-1
        set<int> s;
        int i,n=edges.size();
        for(i=0;i<n;++i){
            s.insert(edges[i][0]);
            s.insert(edges[i][1]);
        }
        int m = s.size();
        s.clear();
        vector<vector<int>> graph (m+1);
        for(i=0;i<n;++i){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            if(graph[u].size() == m-1) return u;
            if(graph[v].size() == m-1) return v;
        }
        return 0;
    }
};