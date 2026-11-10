class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int i,n=arrival.size();
        set<int> s;  // ordered set to store the free or avail servers
        for(i=0;i<k;++i){
            s.insert(i); // intially all are avail/free
        }
        //we need a min pq based on the time a server takes to finsih the current request
        priority_queue<pair<int,int>,  vector<pair<int,int>> , greater<>> pq;
        unordered_map<int,int> mp; //map is to keep the count of how many request each server is handling
        for(i=0;i<n;++i){
            int time = arrival[i];
            //if any servers freed add to set
            while(pq.size() > 0  && pq.top().first <= time){
                s.insert(pq.top().second);
                pq.pop();
            }
            if(s.empty()) continue; //if no free servers, drop/skip the curr request
            // first check if any server from i%k.... k servers avail
            auto it = s.lower_bound(i%k); //if i%k is not free then it check for i%k+1
            if(it == s.end()){
                it = s.begin(); //if no pos >= i%k found, then start from the beginning of avail servers
            }
            int pos = *it ; //pos = some jth server
            s.erase(it); //a server is assigned a req so its not free anymore
            mp[pos]++ ;
            pq.push({time+load[i] , pos});  // push the busy server to the pq with the time at which the server finishes the request
        }
        //find the servers which handled max requests
        int mx = INT_MIN;
        vector<int> ans;
        for(auto x: mp){
            mx = max(mx, x.second);
        }
        for(auto x: mp){
            if(x.second == mx)  ans.push_back(x.first);
        }
        return ans;
    }
};