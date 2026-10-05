class Solution {
public:
    int minRotations(string s) {
        int steps=0, curr=0;
        for(char c : s){
            int idx = c-'0' ;
            int v = min(((10-curr)+idx), (curr+(10-idx)));
            steps += min(abs(idx-curr), v);
            curr = idx;
        }
        return steps;
    }
};