
class Solution {
public:
    int kthGrammar(int n, int k) {

        if (n == 1)
            return 0;

        int half = pow(2, n - 2);

        if (k <= half) {
            // First half → same as previous row
            return kthGrammar(n - 1, k);
        }

        // Second half → opposite of previous row
        int previousPosition = k - half;

        int answer = kthGrammar(n - 1, previousPosition);

        return 1 - answer;
    }
};