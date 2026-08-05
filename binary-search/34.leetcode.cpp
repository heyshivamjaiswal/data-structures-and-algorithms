//Brute force

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1;
        int last = -1;

        for(int i=0; i<n; i++){
            if(nums[i] == target){
            if(first == -1) first = i;
            else last = i;
            }
        }
        return {first , last};
    }
};

//Method 2

// Normal Binary Search
// Found → Return

// First Occurrence
// Found → Save → Go Left

// Last Occurrence
// Found → Save → Go Right

// searchRange()
// ↓
// findFirst()
// findLast()
// return {first, last}

class Solution {
public:


    //Find left
    int findFirst( vector<int>& nums, int target){
        int n=nums.size();
        int low = 0;
        int high = n-1;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                ans = mid;
                high = mid-1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }

    //Find right
    int findLast( vector<int>&nums, int target){
        int n=nums.size();
        int low = 0;
        int high = n-1;
        int ans = -1;

        while(low <= high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target){
                ans = mid;
                low = mid+1;
            }
            else if(nums[mid] < target){ 
                low = mid +1;
            }
            else high = mid-1;
        }
        return ans;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums , target);
        int last = findLast(nums, target);

        return {first , last};
    }
};