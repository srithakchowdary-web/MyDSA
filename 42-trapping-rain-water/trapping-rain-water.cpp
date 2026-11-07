class Solution {
public:
    int trap(vector<int>& height) {
        int i,j,n=height.size();
        stack<int> st;
        int area=0, left;
        for(i=0;i<n;++i){
           while(st.size() > 0  && height[st.top()] < height[i]){
                int mid = st.top();
                st.pop(); 
                if(st.empty()) break;
                left = st.top();
                int h = min(height[left],height[i]);
                area += (i-left-1) * (h - height[mid]);
                
 
            
          }
          st.push(i);
        }
        return area;
    }
};