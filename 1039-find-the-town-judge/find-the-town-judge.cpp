class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)  return 1;
        unordered_map<int,int> incoming;
        unordered_map<int,int> outgoing;

        for(auto x : trust){
            incoming[x[1]]++;
            outgoing[x[0]]++;
        }
        for(auto x : incoming){
            if(x.second == n-1){
                if(outgoing[x.first] == 0)  return x.first;
            }
        }
        return -1;
    }
};