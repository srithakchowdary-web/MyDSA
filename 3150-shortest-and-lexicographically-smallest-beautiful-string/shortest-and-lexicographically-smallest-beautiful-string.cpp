class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i,j,n;
        n= s.size();
        int count=0;
        for(i=0;i<n;++i){
            if(s[i]=='1') count += 1;
            if(count == k){
                j=i;
                break;
            }
        }
        if (count < k)
            return "";
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({j+1, {0,j}});
        for(i=1;i<n;++i){
            
            if(s[i-1]=='1') count -= 1;
            if (count == k) {
                int len = j - i + 1;

                if (len < pq.top().first) {
                    while (!pq.empty())
                        pq.pop();

                    pq.push({len, {i, j}});
                }
                else if (len == pq.top().first) {
                    pq.push({len, {i, j}});
                }
            }
            else{
                j += 1;
                while(j < n){
                    if(s[j]=='1'){
                        count += 1;
                        if(count==k ){
                            int len = j - i + 1;

                            if (len < pq.top().first) {
                              while (!pq.empty())
                                pq.pop();

                              pq.push({len, {i, j}});
                            }
                            else if (len == pq.top().first) {
                                pq.push({len, {i, j}});
                           }
                           break;
                        }
                    }
                    j += 1;
                }
            }
        }
        vector<string> v;
        while(!pq.empty()){
            auto [len, pos] = pq.top();
            pq.pop();

            int l = pos.first;
            int r = pos.second;

            v.push_back(s.substr(l, r - l + 1));
        }
        sort(v.begin(), v.end());
        return v[0];
    }
};