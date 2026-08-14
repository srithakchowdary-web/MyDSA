class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mp;
        for(string s: wordList){
            mp[s]++;
        }
        if(!mp.count(endWord)) return 0;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        int i;
        while(!q.empty()){
            auto [word,dist] = q.front();
            q.pop(); 
            if(word==endWord)  return dist;
            int n = word.size();
            for(i=0;i<n;++i){
                string s = word;
                for(int j=0;j<26;++j){
                    s[i] = j+'a';
                    if(mp.count(s) && mp[s] > 0){
                        q.push({s,dist+1});
                        mp[s]--;
                    }
                }
            } 
        }
        return 0;
    }
};