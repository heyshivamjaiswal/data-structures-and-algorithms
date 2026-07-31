// • Collision happens only when → Stack Top is positive AND Current asteroid is negative.
// • Remove all smaller positive asteroids.
// • If sizes are equal → both explode.
// • If no collision remains (stack empty or top negative) → current asteroid survives.

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        // Stack stores asteroids that have survived so far
        vector<int> st;

        int n = asteroids.size();

        for (int i = 0; i < n; i++) {

            // Positive asteroid → moving right
            // It cannot collide with previous left-moving asteroids,
            // so simply push it.
            if (asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            }

            // Negative asteroid → moving left
            else {

                // Collision is possible only if:
                // 1. Stack is not empty
                // 2. Top asteroid is moving right (positive)
                // 3. Current left-moving asteroid is larger
                // Keep destroying smaller right-moving asteroids.
                while (!st.empty() &&
                       st.back() > 0 &&
                       st.back() < abs(asteroids[i])) {

                    st.pop_back();
                }

                // Both asteroids have the same size.
                // Both explode.
                if (!st.empty() &&
                    st.back() == abs(asteroids[i])) {

                    st.pop_back();
                }

                // Push current asteroid if:
                // 1. No asteroid is left to collide with, OR
                // 2. Top asteroid is also moving left.
                else if (st.empty() || st.back() < 0) {

                    st.push_back(asteroids[i]);
                }

                // Else:
                // Top asteroid is larger and moving right.
                // Current asteroid gets destroyed.
            }
        }

        return st;
    }
};