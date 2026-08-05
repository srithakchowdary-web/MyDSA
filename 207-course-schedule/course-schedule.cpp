class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //check for dag; if its a dag then it returns true else should return false.
        //usinh kahn's algo
        vector<int> indegree (numCourses);
        vector<vector<int>> graph(numCourses);
        int i;
        for(int i=0;i<prerequisites.size();++i){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(i=0;i<numCourses;++i){
            for(int x : graph[i])  indegree[x]++;
        }
        queue<int> q;
        for(i=0;i<numCourses;++i)  {
            if(indegree[i]==0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(int x : graph[node]){
                indegree[x]--;
                if(indegree[x]==0)  q.push(x);
            }
        }
        return count == numCourses ;
    }
    
};