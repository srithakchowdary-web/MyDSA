class Solution {
public:
    bool static cmp (vector<int>& a , vector<int>&  b){
        // > -- descending order, < -- ascending order
        return a[1] <  b[1];
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
         
        int l=logs.size(), m=queries.size();
        unordered_map<int,int> mp;
        int ans=0 ;
        vector<int> arr(m);
        sort(logs.begin(), logs.end(), cmp);
        vector<pair<int,int>> qs;

        for(int i = 0; i < m; ++i) {
            qs.push_back({queries[i], i});
        } 
        sort(qs.begin(), qs.end());
        int rt=0, lt=0;
        for(auto [time, idx] : qs){
             
            if(x > time) continue;
            int low = time-x ;
            int high = time;
            //2 pointer approach to find which are not in range
            // val <= high; add them to ur map
            while(rt < l && logs[rt][1] <= high){
                if(mp[logs[rt][0]] == 0) ans++;   
                mp[logs[rt][0]] ++ ;             
                ++rt;
            }
            // suffix: times less than low
            while(lt < rt && logs[lt][1] < low){
                mp[logs[lt][0]]--;
                if(mp[logs[lt][0]] == 0) --ans;
                ++lt;
            }
             
            arr[idx] = n-ans;
        }
        return arr;
    }
};