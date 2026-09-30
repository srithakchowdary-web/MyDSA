class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<int> st;
        int n = seq.size();
        vector<int> ans ;
        for(char c : seq){
            if(c == '('){
                if(st.empty()) st.push(0);
                else if(st.top()==0)  st.push(1);
                else st.push(0);
                ans.push_back(st.top());
            }
            else{
                if(st.top()==0){
                    ans.push_back(0);
                    st.pop();
                }
                else{
                    ans.push_back(1);
                    st.pop();
                }
            }
        }
        return ans;
    }
};