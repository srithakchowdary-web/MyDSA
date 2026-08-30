class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<pair<int,int>>> graph(n);

        for(auto x : edges){
            graph[x[0]].push_back({x[1], x[2]});
            graph[x[1]].push_back({x[0], x[2]});
        }

        vector<int> ans(n, 0);

        // Run Dijkstra from every city
        for(int source = 0; source < n; ++source){

            priority_queue<
                pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>
            > pq;

            vector<int> dist(n, INT_MAX);

            dist[source] = 0;
            pq.push({0, source});

            while(!pq.empty()){

                auto [d, node] = pq.top();
                pq.pop();

                if(d > dist[node])
                    continue;

                if(d > distanceThreshold)
                    continue;

                for(auto v : graph[node]){

                    int city = v.first;
                    int weight = v.second;

                    if(d + weight <= distanceThreshold &&
                       d + weight < dist[city]){

                        dist[city] = d + weight;

                        pq.push({dist[city], city});
                    }
                }
            }

            // Count reachable cities
            for(int i = 0; i < n; ++i){
                if(i != source && dist[i] <= distanceThreshold){
                    ans[source]++;
                }
            }
        }

        int val = INT_MAX;
        int city = -1;

        for(int i = 0; i < n; ++i){
 
            if(ans[i] <= val){
                val = ans[i];
                city = i;
            }
        }

        return city;
    }
};