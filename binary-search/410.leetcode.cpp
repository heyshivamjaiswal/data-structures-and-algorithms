



class Solution {
public:

   /**
    * Helper function to count how many sub-arrays (partitions) are needed
    * if the maximum allowed sum of any sub-array is limited to 'maxSum'.
    */
   int countPartitions(vector<int>& nums, int maxSum) {
    int partitions = 1;      // Start with at least 1 sub-array
    long subarraySum = 0;    // Keeps track of the current running sum

    for (int num : nums) {
        // If adding the current number doesn't exceed our allowed limit
        if (subarraySum + num <= maxSum) {
            subarraySum += num; // Include it in the current sub-array
        }
        else {
            // The limit is exceeded, so we must start a new sub-array
            partitions++;
            subarraySum = num; // Current number becomes the start of the new sub-array
        }
    }
    return partitions; // Return the total number of partitions needed
   }

    /**
     * Main function to find the minimized largest sum among k sub-arrays.
     */
    int splitArray(vector<int>& nums, int k) {
        // 'low' represents the minimum possible answer.
        // A single element cannot be split, so the largest sum must be at least the largest single number.
        int low = *max_element(nums.begin(), nums.end());
        
        // 'high' represents the maximum possible answer.
        // If k = 1, we don't split at all, so the total sum is the entire array sum.
        int high = accumulate(nums.begin(), nums.end(), 0);

        // Binary search to find the optimal maximum sub-array sum
        while (low <= high) {
            // Find the midpoint value to test as our target maximum sum.
            // Using 'low + (high - low) / 2' instead of '(low + high) / 2' prevents potential integer overflow.
            int mid = low + (high - low) / 2;

            // Check how many partitions we actually need if the max sub-array sum is limited to 'mid'
            int partitions = countPartitions(nums, mid);
            
            // If we need MORE than 'k' partitions, 'mid' is too small.
            // We need a larger maximum sum to fit into fewer partitions.
            if (partitions > k) {
                low = mid + 1; // Shift search range to the right half
            }
            // If we need fewer or exactly 'k' partitions, 'mid' is valid.
            // But we want to find the MINIMUM possible valid maximum sum, so we look for smaller values.
            else {
                high = mid - 1; // Shift search range to the left half
            }
        }
        
        // When the loop ends, 'low' will point to the smallest valid maximum sub-array sum.
        return low;
    }
};
