class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //reverse graph and topological sort depending on outdegree
        int i,n=graph.size();
        vector<vector<int>> adj(n);
        vector<int> outdegree(n);
        for(i=0;i<n;++i){
            for(int x : graph[i]){
                adj[x].push_back(i);
                outdegree[i]++;
            }
        }
        queue<int> q;
        for(i=0;i<n;++i){
            if(outdegree[i]==0)  q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int x : adj[node]){
                outdegree[x]--;
                if(outdegree[x]==0)  q.push(x);
            }
        }
        vector<int> ans;
        for(i=0;i<n;++i){
            if(outdegree[i]==0)  ans.push_back(i);
        }
        return ans;
    }
};