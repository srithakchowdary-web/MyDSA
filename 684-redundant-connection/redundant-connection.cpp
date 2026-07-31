class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int i,j,n=edges.size(),ans;
        for(i=0;i<n;++i){
            vector<vector<int>> graph(n+1);
            for(j=0;j<n;++j){
                if(i==j) continue;
                graph[edges[j][0]].push_back(edges[j][1]);
                graph[edges[j][1]].push_back(edges[j][0]);
            }
            stack<int> st;
            vector<bool> vis(n+1,false);
            int count=1;
            st.push(1);
            vis[1]=true;
            while(!st.empty()){
                int node =  st.top() ;
                st.pop();
                for(int x: graph[node]){
                    if(!vis[x]){
                        vis[x]=true;
                        st.push(x);
                        ++count;
                    }
                }
            }
            if(count == n) ans = i;
        }
        return edges[ans];
    }
};