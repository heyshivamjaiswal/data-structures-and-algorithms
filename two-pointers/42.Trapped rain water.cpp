//METHOD 1- BRUTE FORCE

// We do NOT calculate water between walls.
// We calculate water above every individual bar, suppose we are at index i we look at left (leftMax) of i the biggest num and right of the biggest num (rightMax)
//then choose smalllest among those two chosen walls and subtract the current index height- min(leftMax , rightMax) - height[i]
// then sum all those values.

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;
        
        
        for(int i = 0 ; i < n; i++){ //going to each indices
          int leftMax = 0, rightMax = 0;

          for(int j = 0 ; j <= i; j++){ //checking for right of all element from current standing index 
           rightMax = max(rightMax , height[j]); //if found update rightMax
          }   

          for(int j = i ; j < n; j++){ // same as above just checking for left
            leftMax = max(leftMax , height[j]);
          }
          totalWater += min(leftMax , rightMax) - height[i]; // calculating total water collected
        }
        return totalWater;
    }
};


//Method 2
// • Water above one bar = min(leftMax, rightMax) - height.
// • Precompute leftMax[] and rightMax[].
// • No repeated searching.
// • Sum water for every bar.


// Whenever you see:

// "For every index, find maximum/minimum on the left."
// "For every index, find maximum/minimum on the right."
// "Repeated scanning of left/right in brute force."

// Think immediately:

// Prefix/Suffix Precomputatio



class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int>leftMax(n);
        vector<int>rightMax(n);

        //prefix
        leftMax[0] = height[0];
        for(int i = 1 ; i< n; i++){
            leftMax[i] = max(leftMax[i-1] , height[i]);
        }

        //suffix 
        rightMax[n-1] = height[n-1];
          for(int i=n-2;i>=0;i--){
        rightMax[i] = max(rightMax[i+1], height[i]);
        }

        int totalWater = 0;

        for(int i = 0; i<n; i++){
            totalWater += min(leftMax[i], rightMax[i]) - height[i];
        }
        return totalWater;
    }
};

//METHOD 3 (optimal solution)• Water is calculated one bar at a time.

// • Smaller boundary always decides the water level.
// • leftMax < rightMax → process left.
// • rightMax <= leftMax → process right.
// • Move only one pointer each iteration.

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        // Two pointers
        int left = 0;
        int right = n - 1;

        // Highest wall seen so far from left and right
        int leftMax = height[left];
        int rightMax = height[right];

        // Stores total trapped water
        int water = 0;

        while (left < right) {

            // Left wall is the limiting boundary
            if (leftMax < rightMax) {

                // Move left pointer
                left++;

                // Update tallest wall seen from left
                leftMax = max(leftMax, height[left]);

                // Water above current bar
                water += leftMax - height[left];

            }
            // Right wall is the limiting boundary
            else {

                // Move right pointer
                right--;

                // Update tallest wall seen from right
                rightMax = max(rightMax, height[right]);

                // Water above current bar
                water += rightMax - height[right];
            }
        }

        return water;
    }
};
