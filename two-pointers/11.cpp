//the height will be min(h[i] , h[j]) to contain the water
//if we enouter bigger height we will stick to it and move the other height which is lesser , and if this height becomes lesser then other then we will move this height


class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0 , j = height.size() -1;
        
        int maxWater = 0;
        while( i < j){
            int w = j-i;
            int h = min(height[i] , height[j]);

            int area = h*w;
            maxWater = max(maxWater , area);

            if(height[i] > height[j]){
                j--;
            }
            else i++;
        }
        return maxWater;
    }
};