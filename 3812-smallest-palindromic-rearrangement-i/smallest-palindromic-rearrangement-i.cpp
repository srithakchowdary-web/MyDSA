class Solution {
public:
    string smallestPalindrome(string s) {
        int i,n;
        n = s.size();
        if(n==1) return s;
        //sort(s.begin(),s.end());
        vector<int> v(26,0);
        int mid;
        for(i=0;i<n;++i){
            v[s[i]-'a']++;
        } 
        mid = n/2; 
        int j=0,k=n-1;
        for(i=0;i<26;++i){
            //
            int num = v[i];
            if(num==0) continue;
            char c= 'a'+i;
            while(num>1 && j<k){
                s[j]=c;
                s[k]=c;
                j++;
                k--;
                num-=2;
            }

            if(num==1)
                s[mid]=c;
        }
        return s;
    }
};