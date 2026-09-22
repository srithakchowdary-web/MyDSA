class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<bool> vis(n,false);
        
        //for(int i=0;i<n;++i){
         //   graph[i].push_back(edges[i])
        //}
        queue<pair<int,int>> q;
        q.push({node1,0});
        unordered_map<int,int> mp;
        while(!q.empty()){
            auto [node, d] = q.front();
            q.pop();
            if(vis[node])
                continue;
            vis[node] = true;
            mp[node] = d;
            if(edges[node] != -1)
                q.push({edges[node], d + 1});
        }
        fill(vis.begin(), vis.end(), false);
        q.push({node2,0});
        int dis=INT_MAX, ans=-1;
        while(!q.empty()){
            auto [node, d] = q.front();
            q.pop();
            if(vis[node]) continue;
            vis[node] = true;
            if(mp.find(node) != mp.end()){
                int dist =   max(d,mp[node]);
                if(dist < dis){
                    dis = dist;
                    ans = node;
                }
                else if(dist == dis){
                    ans = min(ans, node);
                }
            }
            if(edges[node] != -1){
                q.push({edges[node], d+1});
            }
        }
        return ans;
    }
};