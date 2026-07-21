class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        const long long MOD = 1e9+7;
        int i,j,k,n=arr.size();
        long long count =0;
        for(i=0;i<n-2;++i){
            j = i+1;
            k = n-1;
            while(j<k){
                long long sum = 1LL * arr[i] + arr[j] + arr[k];
                if(sum > target) --k;
                else if(sum < target)  ++j;
                else{
                    if(arr[j]==arr[k]){
                        long long m = k-j;
                        count = (count + (m * (m+1) / 2)) % MOD;
                        break;
                    }
                    else{
                        int fj = 1;
                        while(j+fj < k  && arr[j+fj]==arr[j]) ++fj;
                        int fk = 1;
                        while(k-fk > j && arr[k-fk]==arr[k])  ++fk;
                        count = (count + 1LL * fj * fk) % MOD;
                        j += fj;
                        k -= fk ; 
                    }
                    
                }
            }
        }
        //if(cj>1 && ck>1)  count = (count+(cj*ck)) % MOD;
        return (int)count;
    }
};