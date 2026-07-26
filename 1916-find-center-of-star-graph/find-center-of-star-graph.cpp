class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //jiska edges and no.of vertices will be n-1
        //unordered_map<int,int> mp;
        int b = edges[0][0];
        int a = edges[0][1];
        if((edges[1][1]==a)  || (edges[1][0]==a)) return a;
        if((edges[1][0]==b)  || (edges[1][1]==b)) return b;
        return 0;
    }
};