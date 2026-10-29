class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> v;
        int i,j;
        if(m==1 && n==1) {
            string s =".";
            v.push_back(s);
            return v;
        }
        else if(m==1){
            v.push_back(string(n, '.'));   
            return v;
        }
        else if(n==1){
            for (i = 0; i < m; ++i)
                v.push_back(".");       
            return v;
        }
        else{
            for(i=0;i<m;++i){
                string s;
                for(j=0;j<n;++j){
                    if(i == 0) s.push_back('.');
                    else if(i > 0 && j==n-1) s.push_back('.');
                    else s.push_back('#');
                }
                v.push_back(s);
            }
        }
        return v;
    }
};