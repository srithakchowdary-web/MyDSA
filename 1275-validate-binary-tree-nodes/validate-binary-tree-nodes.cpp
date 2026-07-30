class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> vis(n,false);
        vector<int> indegree(n,0);
        for(int i=0;i<n;++i){
            if(leftChild[i]!= -1) indegree[leftChild[i]]++;
            if(rightChild[i] != -1) indegree[rightChild[i]]++;
        }
        int count=0,root=-1;
        for(int i=0;i<n;++i){
            if(indegree[i] > 1) return false;
            if(indegree[i]==0){
                ++count;
                if(count > 1) return false;
                root = i;
            }
        }
        if(root == -1) return false;
        
        stack<int> st;
        st.push(root);
        vis[root]=true;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            int lc= leftChild[node];
            int rc = rightChild[node];
            if(lc != -1){
                if(vis[lc]) return false;
                vis[lc] = true;
                st.push(lc);
            }
            if(rc != -1){
                if(vis[rc]) return false;
                vis[rc] =true;
                st.push(rc);
            }
        }
        for(int i=0;i<n;++i){
            if(!vis[i]) return false;
        }
        return true;
    }
};