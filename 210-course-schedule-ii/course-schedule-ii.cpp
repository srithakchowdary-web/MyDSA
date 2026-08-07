class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int i,count=0;
        vector<vector<int>> graph(numCourses);
        for(i=0;i<prerequisites.size();++i){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> inorder(numCourses);
        for(i=0;i<numCourses;++i){
            for(int x : graph[i]) inorder[x]++;
        }
        queue<int> q;
        for(i=0;i<numCourses;++i){
            if(inorder[i]==0)  q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ++count;
            ans.push_back(node);
            for(int x: graph[node]){
                inorder[x]--;
                if(inorder[x]==0) q.push(x);
            }
        }
        if(count != numCourses) return {};
        //reverse(ans.begin(),ans.end());
        return ans;
    }
};