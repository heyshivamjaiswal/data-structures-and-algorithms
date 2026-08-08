//Type 1

//Iterative 
//complexity is O(logN), where N = size of the given array.


class Solution {
public:
    // Function to perform Binary Search on sorted array
    int binarySearch(vector& nums, int target) {
        int n = nums.size(); // size of the array
        int low = 0, high = n - 1;

        // Keep searching until low crosses high
        while (low <= high) {
            int mid = (low + high) / 2; // Find the middle index
            if (nums[mid] == target) return mid;       // Target found
            else if (target > nums[mid]) low = mid + 1; // Search in right half
            else high = mid - 1;                        // Search in left half
        }
        return -1; // Target not found
    }
};

//Recursive
//O(logN), where N = size of the given array.


class Solution {
public:
    // Recursive Binary Search function
    int binarySearch(vector& nums, int low, int high, int target) {
        if (low > high) return -1; // Base case: target not found

        // Find middle index
        int mid = (low + high) / 2;

        // If target is found at mid
        if (nums[mid] == target) return mid;
        // If target is greater, search right half
        else if (target > nums[mid])
            return binarySearch(nums, mid + 1, high, target);
        // Otherwise, search left half
        return binarySearch(nums, low, mid - 1, target);
    }

    // Public function to initiate search
    int search(vector& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};

//-------------------------------------------------//
//Type 2

class Solution {
public:

    bool canDo(vector<int>& nums, int x) {

        // Check whether x is a valid answer.

        return true;
    }

    int solve(vector<int>& nums) {

        int low = /* smallest possible answer */;
        int high = /* largest possible answer */;

        while(low < high) {

            int mid = low + (high - low) / 2;

            if(canDo(nums, mid)) {

                // mid works.
                // Search for a smaller valid answer.
                high = mid; //for bigger (maximums) low = mid

            }
            else {

                // mid doesn't work.
                // Need a larger answer.
                low = mid + 1; //mid-1
            }
        }

        return low;
    }
};