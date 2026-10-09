class Solution {
public:
    int minInsertions(string s) {
        int ans=0, i,n=s.size();
        int open =0, close=0;
        for(i=0;i<n;++i){
            if(s[i]=='('){
                if(close > 0){
                    if(open > 0){
                        ans += 1;     
                        open--;
                    }
                    else ans += 2;   
                    close =0;
                }
                open ++ ;
            }
            else{
                ++close;
                if(close == 2){
                    if(open > 0){
                        close = 0;
                        open--;
                    }
                    else{
                        ans += 1;
                        close -= 2;
                    }
                }
            }
        }
        if(open > 0 && close==0){
            ans += 2*open ;
        }
        else if(open > 0 && close >0){
            ans += 2*open  ;
            ans -= close;
        }
        else if(open == 0 && close>0)  ans += 2;

        return ans;
    }
};