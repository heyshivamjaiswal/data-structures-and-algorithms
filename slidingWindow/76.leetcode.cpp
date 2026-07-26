class Solution { 
public: 
    string minWindow(string s, string t) { 
        if(t.empty() || s.empty() || s.size() < t.size()) return ""; 
        
        int n = s.size(); 
        int m = t.size(); 
        int left = 0; 
        int right = 0; 
        int count = 0; 
        int sIndex = -1; 
        int minLen = INT_MAX; 
        
        vector<int> hash(256, 0); 
        
        // Step 1: Map frequencies of characters in t
        for(int i = 0; i < m; i++){ 
            hash[t[i]]++; 
        } 
        
        // Step 2: Expand the right pointer
        while(right < n){ 
            // If the character is expected by t, increment our matched count
            if(hash[s[right]] > 0) {
                count++; 
            }
            hash[s[right]]--; 
            right++; 
            
            // Step 3: Shrink the left pointer when a valid window is found
            while(count == m){ 
                // FIX 1: Correctly calculate and update the minimum length
                if(right - left < minLen){ 
                    minLen = right - left; 
                    sIndex = left; 
                } 
                
                // Put the left character back into the requirement pool
                hash[s[left]]++; 
                // FIX 2: Only decrement count if we genuinely need this character for t
                if(hash[s[left]] > 0) {
                    count--; 
                }
                left++; 
            } 
        } 
        
        // FIX 3: Return the correct substring using the properly saved length
        return sIndex == -1 ? "" : s.substr(sIndex, minLen); 
    } 
};
