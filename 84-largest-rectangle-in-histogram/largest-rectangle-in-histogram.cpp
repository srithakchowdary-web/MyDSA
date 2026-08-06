class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size(),i;
        vector<vector<int>> ans(n);
        stack<int> prev;
        stack<int> next;
        //prev smaller ele
        for(i=0;i<n;++i){
            while(!prev.empty()  && heights[prev.top()] >= heights[i]){
                prev.pop();
            }
            if(!prev.empty())  ans[i].push_back(prev.top());
            else  ans[i].push_back(-1);
            prev.push(i);
        }
        //next smaller element
        for(i=n-1;i>=0;--i){
            while(!next.empty() && heights[next.top()] >= heights[i]){
                next.pop();
            }
            if(!next.empty())  ans[i].push_back(next.top());
            else  ans[i].push_back(n);

            next.push(i);

        }

        //calculationg area
        int val = INT_MIN;
        for(i=0;i<n;++i){
            int area = heights[i]*(ans[i][1]-ans[i][0]-1);
            val = max(val,area);
        }
        return val;
    }
};