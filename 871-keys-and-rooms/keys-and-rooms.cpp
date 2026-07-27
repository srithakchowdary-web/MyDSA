class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int i,n=rooms.size(),count=1;
        stack<int> st;
        st.push(0);
        vector<bool> vis(n,false);
        vis[0]=true;
        while(!st.empty()){
            auto it = rooms[st.top()];
            st.pop();
            for(int x: it){
                if(!vis[x]){
                    vis[x]=true;
                    st.push(x);
                    ++count;
                }
            }
        }
        return count==n;
    }
};