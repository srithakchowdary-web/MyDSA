class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        long long price = LLONG_MAX;
        int i,m=flights.size();
        vector<vector<pair<int,int>>> graph(n);
        //int i,n=flights.size();
        for(i=0;i<m;++i){
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        stack<tuple<int,long long,int>> st;
        // st -> node, cost and stops(k)
        vector<vector<long long>> dist(n, vector<long long> (k+2, LLONG_MAX));
        dist[src][0]=0;
        //dist - index=node values, each k+1 no.of col [k stops = k+1 flights], intially dist to ecah node is infinite
        st.push({src,0,0});
        while(!st.empty()){
            auto [node,cost,stops] = st.top();
            st.pop();
             
            if(stops > k+1)  continue;
            if(node == dst) {
                price = min(price,cost);
                continue;
            }
            if(stops == k+1)  continue;
            for(auto x : graph[node]){
                int destination = x.first;
                int weight = x.second;
                long long newCost =cost+weight;
                if(newCost >= price){
                    continue;
                }
                if(newCost >= dist[destination][stops+1]) continue; //no improvement
                dist[destination][stops+1] = newCost;
                st.push({destination,newCost, stops+1});
            }
        }
        return price==LLONG_MAX ? -1 : (int)price;
    }
};
// without any vecator to store the distances from src to the dst, the algo runs in exponential time. SO we need a vector to store the distances, index acts as the node value. Add a node to stack only if the newCost is less than the alredy determined cost/\.