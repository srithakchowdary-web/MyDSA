class Solution {
public:
    string reverseParentheses(string s) {
        int i;
        size_t n=s.size();
        stack<int> open; 
        for(i=0;i<n;++i){
            if(s[i]=='(')  open.push(i);
            else if(s[i]==')')  {
                int j = open.top();
                open.pop();
                reverse(s.begin()+j, s.begin()+i+1);
            }
        }
        string ans;
        for(char c :s){
            if(c=='(' || c==')') continue;
            ans.push_back(c);
        }
        return ans;
    }
};