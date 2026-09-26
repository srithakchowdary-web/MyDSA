class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        int n = knowledge.size();
        for(int i=0;i<n;++i){
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        int i=0;
        int m = s.size();
        while(i < m){
            if(s[i]=='('){
                size_t end = s.find(')', i+1);
                string key = s.substr(i+1, end-i-1);
                if(mp.find(key) == mp.end()){
                    s.replace(i, end-i+1, "?");
                    i = i + 1;
                    m = s.size();          
                }
                else {
                    s.replace(i, end-i+1, mp[key]);
                    i = i + mp[key].size();
                    m = s.size();          
                }
                continue;
            }
            i+=1;
        }
        return s;
    }
};