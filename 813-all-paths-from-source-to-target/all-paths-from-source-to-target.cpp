class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void backtrack(vector<vector<int>>& graph, int src, int dest){
        curr.push_back(src);
        if(src==dest) {
            ans.push_back(curr);
            //curr.pop_back();
            //return;
        }
        for(int x : graph[src]){
            backtrack(graph,x,dest);
        }
        curr.pop_back(); 
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //stack<int> st;
        //vector<bool> vis(graph.size(),false);
        backtrack(graph,0,graph.size()-1);
        return ans;

    }
};