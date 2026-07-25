//METHOD 1

// • Build frequency of s1 once.
// • Check every window of length m in s2.
// • Rebuild the window's frequency from scratch each time.
// • If both frequency arrays match, a permutation exists.

//Total complexity

// O(m)

// +

// O((n-m+1) × m)

// +

// O((n-m+1) × 26)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int m = s1.size();
        int n = s2.size();

        if (m > n)
            return false;

        // Frequency of s1
        vector<int> freq1(26, 0);

        for (char ch : s1)
            freq1[ch - 'a']++;

        // Check every possible window
        for (int i = 0; i <= n - m; i++) {

            vector<int> freq2(26, 0);

            // Build frequency for current window
            for (int j = i; j < i + m; j++) {
                freq2[s2[j] - 'a']++;
            }

            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};

//METHOD 2

// • Permutation ⇒ same frequency and same length.
// • Build frequency for s1 and the first window.
// • Slide by removing one left character and adding one right character.
// • Compare the two frequency arrays after each slide.

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int m = s1.size();
        int n = s2.size();

        if (m > n)
            return false;

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        // Frequency of s1
        for (char ch : s1)
            need[ch - 'a']++;

        // Build first window
        for (int i = 0; i < m; i++)
            window[s2[i] - 'a']++;

        // Compare first window
        if (need == window)
            return true;

        // Slide the window
        for (int right = m; right < n; right++) {

            // Remove left character
            window[s2[right - m] - 'a']--;

            // Add new right character
            window[s2[right] - 'a']++;

            // Compare frequencies
            if (need == window)
                return true;
        }

        return false;
    }
};