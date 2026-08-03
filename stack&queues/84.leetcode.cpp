// • Stack stores indices of increasing heights.
// • A smaller bar ends the rectangle of taller bars.
// • While popping:
//     height = popped bar
//     right = current index
//     left = new stack top (or -1)
// • width = right - left - 1
// • area = height × width


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxArea = 0;
        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = st.top(); st.pop();
                int nse = i;
                int pse = st.empty()? -1 : st.top();
                maxArea = max(heights[element]*(nse - pse -1) , maxArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = heights.size();
            int element = st.top(); st.pop();
            int pse = st.empty()? -1 : st.top();
            maxArea = max ( maxArea , (nse-pse -1)*heights[element]);
        }
        return maxArea;
    }
};