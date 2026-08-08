class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        int i,m=queries.size();
        for(int i=0;i<prerequisites.size();++i){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> ans(m);
        for(i=0;i<m;++i){
            queue<int> q;
            vector<bool> vis(numCourses, false);
            q.push(queries[i][0]);
            vis[queries[i][0]] = true;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                if(node == queries[i][1])  {
                    ans[i]=true;
                    break;
                }
                for(int x: graph[node]){
                    if(!vis[x]){
                        q.push(x);
                        vis[x]=true;
                    }
                }
            }
        }
        return ans;
    }
};