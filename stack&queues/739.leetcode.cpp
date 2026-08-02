// • Traverse from right because we need future days.
// • Pop all temperatures <= current.
// • Stack top becomes nearest warmer day.
// • Push current index for future comparisons.


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n,0);
        stack<int>st; //store indecies 

        for(int i=n-1; i>=0; i--){
            
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }

            if(!st.empty()){
                ans[i]= st.top() -i;
            }
            st.push(i);
        }
        return ans;
    }
};