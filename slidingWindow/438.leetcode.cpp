//Hint

// • Same algorithm as LC 567.
// • Fixed window = pattern length.
// • Slide by removing left and adding right.
// • Instead of returning true, store the window's starting index.

// Character Entering  → right

// Character Leaving   → right - m

// Window Start        → right - m + 1

// 1. Build the first complete window.
// 2. Process (check/update) the first window.
// 3. Then start sliding from the next character.

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<int> ans;

        if(m > n)
            return ans;

        vector<int> need(26,0);
        vector<int> window(26,0);

        // Build frequency of pattern
        for(char ch : p)
            need[ch-'a']++;

        // Build first window
        for(int i=0;i<m;i++)
            window[s[i]-'a']++;

        // Check first window
        if(need==window)
            ans.push_back(0);

        // Slide window
        for(int right=m; right<n; right++){

            // Remove left character
            window[s[right-m]-'a']--;

            // Add new character
            window[s[right]-'a']++;

            // Current window starts here
            int left = right-m+1;

            if(need==window)
                ans.push_back(left);
        }

        return ans;
    }
};