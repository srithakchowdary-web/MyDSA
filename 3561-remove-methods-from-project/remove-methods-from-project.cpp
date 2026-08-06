class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        vector<int> ans;
        if(invocations.size() == 0){//base case
            for(int i = 0; i < n; i++){
                if(i != k) ans.push_back(i);
            }
            return ans;
        }
        int i;
        for(i=0;i<invocations.size();++i){
            graph[invocations[i][0]].push_back(invocations[i][1]);
        }
        vector<bool> vis(n,false);
        vis[k]=true;
        stack<int> st;
        st.push(k);
        // mark suspicious terms => vis[term] = true
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(int x: graph[node]){
                if(!vis[x]){
                    vis[x]=true;
                    st.push(x);
                }
            }
        }
        for(auto x : invocations){
            if(!vis[x[0]]  && vis[x[1]]){
                for(i=0;i<n;++i){
                    ans.push_back(i);

                }
                return ans;
            }
        }
        for(i=0;i<n;++i){
            if(!vis[i])  ans.push_back(i);
        }
        return ans;
    }
};