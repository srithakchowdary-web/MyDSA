class Solution {
public:
    string removeOuterParentheses(string s) {
        int i, n, open =0, close=0;
        n = s.size();
        int start;
        for(i=0;i<n;++i){
            if(s[i]=='('  && open==0  && close==0){
                start = i;
                ++open;
            }
            else if(s[i] == '(')  ++open;
            else if(s[i] == ')')   {
                ++close;
                if(open == close){
                    s[start] = 'a';
                    s[i] = 'a';
                    open =0 ;
                    close = 0;
                }
            }
        }
        string ans;
        for(char c : s){
            if(c == 'a')  continue;
            ans.push_back(c);
        }
        return ans;
    }
};