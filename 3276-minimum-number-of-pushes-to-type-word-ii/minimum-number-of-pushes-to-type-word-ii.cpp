class Solution {
public:
    int minimumPushes(string word) {
        unordered_map <char,int> mp;
        for(char c: word){
            mp[c]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto x: mp){
            pq.push({x.second,x.first});
        }
        mp.clear();
        int c=0,sum=0;
        while(!pq.empty()){
            c += 1;
            auto x = pq.top();
            pq.pop();
            if(c <=8 )  sum += x.first;
            else if(c>8 && c<=16)  sum += (x.first*2);
            else if(c>16 && c<=24)  sum += (x.first*3);
            else sum += (x.first*4);
        }
        return sum;
    }
};