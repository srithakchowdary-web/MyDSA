class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;
        for(auto x : reservedSeats){
            mp[x[0]].push_back(x[1]);
        }
        int i,j, ans=0;
        int size = mp.size();
        ans += (n-size)*2 ;
        for(auto x : mp) {
            
            vector<int> v = x.second;
            sort(v.begin(),v.end());
            int m = v.size();
            bool left=true;
            bool rt= true;
            bool mid = true;
            for(j=0;j<m;++j){
                if(v[j]==2 || v[j]==3  || v[j]==4  || v[j]==5)  left = false;
                if(v[j]==4 || v[j]==5  || v[j]==6  || v[j]==7)  mid = false;
                if(v[j]==6 || v[j]==7  || v[j]==8  || v[j]==9)  rt = false;
            }
            if(left && rt) {
                ans += 2;
                continue;
            }
            if(left || rt || mid)  ans += 1;
        }
        return ans;
    }
};