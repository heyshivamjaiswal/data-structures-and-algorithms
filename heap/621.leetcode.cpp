//Method 1 (max heap)

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Count frequency
        vector<int> freq(26, 0);

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Max heap
        priority_queue<int> pq;

        for (int f : freq) {
            if (f > 0) {
                pq.push(f);
            }
        }

        int time = 0;

        while (!pq.empty()) {

            vector<int> temp;

            // One cycle = n + 1
            for (int i = 0; i <= n; i++) {

                if (!pq.empty()) {

                    int f = pq.top();
                    pq.pop();

                    f--;

                    if (f > 0) {
                        temp.push_back(f);
                    }
                }

                time++;

                // Everything finished
                if (pq.empty() && temp.empty()) {
                    break;
                }
            }

            // Put remaining frequencies back
            for (int f : temp) {
                pq.push(f);
            }
        }

        return time;
    }
};


//Method 2

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        int maxFreq = 0;

        for (int f : freq) {
            maxFreq = max(maxFreq, f);
        }

        int maxCount = 0;

        for (int f : freq) {
            if (f == maxFreq) {
                maxCount++;
            }
        }

        int result =
            (maxFreq - 1) * (n + 1) + maxCount;

        return max((int)tasks.size(), result);
    }
};
