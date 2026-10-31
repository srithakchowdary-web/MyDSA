class Solution {
public:
    static bool cmp (vector<int>& a , vector<int>& b){
        //if(a[0] < b[0]) return true;
        if(a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0];
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), cmp);
        int n = clips.size(), i=0;
        int end=0;
        if(clips.empty() || clips[0][0] != 0)
            return -1;
        while(i < n && clips[i][0]==0){
            //if(clips[i][0] != 0) break;
            end =max(end, clips[i][1]) ;
            ++i;
        }
        int ans = 1 ;
        while(end < time && i < n){
            int maxi = end;
            //int beg=start-1;
            while(i<n && clips[i][0] <= end ){
                 
                maxi = max(maxi, clips[i][1]);
                ++i;
                 
            }
            if(maxi == end) return -1; //no furhter extension of the choices
            ans += 1;
            end = maxi;
           
        }
         if(end < time) return -1;
        return ans;
    }
};