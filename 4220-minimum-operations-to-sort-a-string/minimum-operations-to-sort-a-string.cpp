class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        char min_c='z', max_c='a';
        for(char c : s){
            if(c < min_c)  min_c = c;
            if(c > max_c)  max_c = c;
        }
        string duplicate=s;
        sort(duplicate.begin(), duplicate.end());
        if(s == duplicate) return 0;
        if(n==2) return -1;
        else if(s[0] == min_c  ||  s[n-1] == max_c)  return 1;
        else if(s[n-1] == min_c  &&  s[0] == max_c  && count(s.begin(), s.end(), min_c) == 1 && count(s.begin(), s.end(), max_c) == 1)  return 3;
        // 3 -> only when both min and max are not at correct positons and they are repaeted only once
        //else if(s[0] != min_c  ||  s[0] != max_c)  return 2;
        return 2;
    }
};