class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        stack<int> st;
        for(char c : s){
            if(c == '(') st.push(c);
            else {
                if(!st.empty()){
                    st.pop();
                }
                else count++;
            }
        }
        return st.size()+count ;
    }
};