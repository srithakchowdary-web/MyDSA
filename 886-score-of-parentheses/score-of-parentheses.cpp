class Solution {
public:
    int scoreOfParentheses(string s) {
        int i, n=s.size();
        int ans = 0, count=0;
        for(i=0; i<n ;++i){
            if (s[i]=='(')  count++;
            if(s[i] == ')'){
                count -= 1 ;
                if(s[i-1]=='('){
                    ans += pow(2,count);
                }
                
            }
        }
        return ans;
    }
};