class Solution {
public:
    static bool fn(const vector<int>& v1, const vector<int>& v2){
        return v1[1] < v2[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), fn);
        int i,n=courses.size();
        priority_queue<int> pq;
        int ans=0, time=0;
        for(i=0;i<n;++i){
            time += courses[i][0];
            ans += 1;
            pq.push(courses[i][0]);
            if(time > courses[i][1]){
                time -= pq.top();
                pq.pop();
                --ans;
            }
        }
        return ans;
    }
};