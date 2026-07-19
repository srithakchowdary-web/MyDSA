class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        deque<int> dq;
        int i = num.size()-1;
        int extra=0,last_digit,sum ;
        while(i>=0  && k>0){
            last_digit = k%10;
            k /= 10;
            sum = last_digit+extra+num[i];
            if(sum > 9){
                extra=1;
                dq.push_front(sum%10);
            }
            else{
                extra = 0;
                dq.push_front(sum);
            }
            --i;
        }
        while(i >= 0){
            sum = num[i]+extra ;
            dq.push_front(sum%10);
            extra = sum/10;
            --i;
        }
        while(k > 0){
            last_digit = k%10;
            k /= 10;
            sum = last_digit + extra;
            dq.push_front(sum%10);
            extra = sum/10;
        }
        if(extra)  dq.push_front(extra);
        vector<int> ans;
        while(!dq.empty()){
            ans.push_back(dq.front());
            dq.pop_front();
        }
        return ans;
    }
};