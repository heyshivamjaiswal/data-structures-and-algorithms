//METHOD 1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n = s.size();
      int ans = 0;
      for(int i=0; i<n; i++){
        unordered_set<set>st;
        for(int j=i; j<n; j++){
            if(st.count(s[j])) break;

            st.insert(s[j]);

            ans = max(ans , j-i+1);
        }
      }
    }
};

//METHOD 2 (SLIDING WINDOW)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char , int>freq;
        int left = 0;
        int ans = 0;
        for(int right = 0; right < n; right++){
            freq[s[right]]++;

            while(freq[s[right]] > 1){
                freq[s[left]]--;
                left++;
            }
            ans = max(ans , right - left +1);
        }
        return ans;
    }
};