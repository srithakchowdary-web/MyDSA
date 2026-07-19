class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map <int,int> mp;
        //int i,n=arr.size();
        for(int x : arr){
             int v = x*2;
             if(mp.count(v)) return true;
             if(x%2==0 && mp.count(x/2)) return true;
             mp[x] ++;
        }
        return false;
    }
};