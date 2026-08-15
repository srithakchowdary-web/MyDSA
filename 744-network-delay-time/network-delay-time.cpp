class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto x : times){
            graph[x[0]].push_back({x[1],x[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        while(!pq.empty()){
            auto [ dis, x] = pq.top();
            pq.pop();
            if(dis > dist[x]) continue;
            for(auto [m,weigh] : graph[x]){
                if(weigh+dis < dist[m]){
                    dist[m ] = weigh+dis ;
                    pq.push({dist[m],m});
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n ;++i){
            if(dist[i] ==  INT_MAX) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};