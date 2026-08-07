// Pairs start at EVEN indices before the single element.

// Force mid to be EVEN.

// Compare:
// nums[mid] with nums[mid+1]

// Equal?
// ↓
// Single is on the RIGHT.

// Not Equal?
// ↓
// Single is on the LEFT (or mid itself).

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            // Make sure mid is even
            if (mid % 2 == 1)
                mid--;

            // Pair is correct
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            }
            // Pair is broken
            else {
                right = mid;
            }
        }

        return nums[left];
    }
};