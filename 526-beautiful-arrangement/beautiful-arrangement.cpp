class Solution {
public:
    int count=0;
    vector<int> curr; 
    void solve(int n,vector<bool>& used){
        if(curr.size() == n){ 
            ++count;
            return ;
        }
        int pos = curr.size() + 1;
        for(int i=1;i<=n;++i){
            if(used[i]) continue;
            if(i % pos != 0 && pos % i != 0)
            continue;

            curr.push_back(i);
            used[i]=true;
            solve(n,used);
            curr.pop_back();
            used[i]=false;
        }
    }
    int countArrangement(int n) {
        vector<bool> used(n+1,false);
        solve(n,used);
        return count;
    }
};