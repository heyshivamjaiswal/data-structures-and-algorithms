// Search Space = Eating Speed (k)

// 1 ---------------- maxPile

// Guess a speed.

// ↓

// Calculate total hours.

// ↓

// hours <= h ?

// YES
// ↓
// Speed works.
// Try slower.
// (right = mid)

// NO
// ↓
// Too slow.
// Eat faster.
// (left = mid + 1)

// Return left.


class Solution {
public:

    // Returns total hours needed if Koko eats at speed = k
    int hoursNeeded(vector<int>& piles, int k) {

        int hours = 0;

        for (int bananas : piles) {

            // Equivalent to ceil(bananas / k)
            hours += (bananas + k - 1) / k;
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;

        // Maximum possible useful speed = largest pile
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {

            int mid = left + (right - left) / 2;

            // Hours needed at current speed
            int hours = hoursNeeded(piles, mid);

            // Current speed works.
            // Try to find a smaller valid speed.
            if (hours <= h) {

                right = mid;

            }
            // Too slow.
            // Increase the eating speed.
            else {

                left = mid + 1;
            }
        }

        // left == right = minimum valid speed
        return left;
    }
};