// Approach 1
// Brute force (sorting)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        sort(s.begin() , s.end());
        sort(t.begin() , t.end());

      return s == t;
    }
};

//Approach 2
// Use map

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<int , int>freq;
        
        //1st loop (add ch in map with frq)
        for(char ch: s){
            freq[ch]++;
        }

        //2nd loop (remove matching ch of s from freq)

        for(char ch: t){
            freq[ch]--;
            
        if(freq[ch] < 0)

        return false;
        }
        return true;
    }
};