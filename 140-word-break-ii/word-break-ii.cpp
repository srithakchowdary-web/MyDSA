class Solution {
public:
    unordered_set<string> st;
    vector<string> ans;
    void backtrack(string& s, int idx, string curr){
        if(idx==s.size()){
            ans.push_back(curr);
            return;
        }
        int j, n=s.size();
        for(j=idx;j<n;++j){
            string word = s.substr(idx, j-idx+1);
            if(st.count(word)){
                if(curr.empty())  backtrack(s, j+1, curr+word);
                else  backtrack(s, j+1, curr+" "+word);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string w : wordDict)  st.insert(w);
        backtrack(s,0, "");
        return ans;
    }
};