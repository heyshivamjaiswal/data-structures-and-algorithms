//METHOD 1

// • Start from every index.
// • Extend the substring to the right.
// • Maintain character frequencies.
// • replacements = windowSize - maxFreq.
// • If replacements > k, stop for this starting index.

class Solution {
public:
    int characterReplacement(string s, int k) {
      int n = s.size();
      int ans = 0;
      for(int i=0; i<n; i++){

        unordered_map<char , int>freq;
        int maxFreq = 0;

        for(int j = i; j<n; j++){
            freq[s[j]]++;

            maxFreq = max(maxFreq , freq[s[j]]);

            int windowSize = j - i +1;

            int replacement = windowSize - maxFreq;

            if(replacement <= k)
                ans = max(ans , windowSize);
                else
                break;
        }
      }  
      return ans;
    }
};


//METHOD 2

// • Keep the most frequent character unchanged.
// • Replacements needed = windowSize - maxFreq.
// • If replacements > k, shrink from the left.
// • maxFreq only increases; never decrease it.


class Solution {
public:
    int characterReplacement(string s, int k) {
      int n = s.size();
      int maxFreq = 0;
      int ans = 0;
      int left =0;
      unordered_map<char , int>freq;

      for(int right = 0; right < n; right++ ){
    
       //Add new element in map
       freq[s[right]]++;

       //Update the maximum freq
       maxFreq = max(maxFreq , freq[s[right]]);

       //check if window is invalid if so then shrink
       while((right - left + 1) - maxFreq > k){
        freq[s[left]]--;
        left++;
       }
       //valid window 
       ans = max(ans , right - left + 1);
      }
      return ans;
    }
};