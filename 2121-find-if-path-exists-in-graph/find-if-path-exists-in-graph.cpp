class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int i ;
        if(  source == destination) return true;
        //if(n>0 && source == destination) return false;
        vector<vector<int>> graph(n);
        for(i=0;i<edges.size();++i){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        stack<int> st;
        st.push(source);
        vector<bool> vis(n,false);
        vis[source] = true;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(node == destination) return true;
            for(int nei : graph[node]){
                if(!vis[nei]){
                    vis[nei]=true;
                    st.push(nei);
                }
            }
        }
        return false;
    }
};