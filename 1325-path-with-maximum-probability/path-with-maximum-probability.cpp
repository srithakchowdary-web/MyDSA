class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> graph(n);
        for(int i=0;i<edges.size();++i){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>> pq;
        vector<double> dist(n, 0.00);
        dist[start_node] = 1.0;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto [prob, node] = pq.top();
            pq.pop();
            if(node == end_node)  return dist[end_node];
            for(auto [x,p] : graph[node]){
                if((p*prob) > dist[x]){
                    dist[x] = p*prob;
                    pq.push({p*prob , x});
                }
            }
        }
        return 0;
    }
};