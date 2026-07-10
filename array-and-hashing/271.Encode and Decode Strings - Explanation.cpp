// 271. Encode and Decode Strings - Explanation

// Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.


/*
----------------------------------------------------
Pattern: String Manipulation | Serialization

Idea:
• Delimiter alone doesn't work because it can exist inside the string.
• Store every string as: length#string.
• During decoding, read the length first, then read exactly that many characters.
• '#' separates the length from the string, NOT different strings.

Key STL:
to_string(x)   -> int to string
stoi(str)      -> string to int
substr(i, len) -> start at i, take len characters

Time:
Encode : O(n)
Decode : O(n)

Space:
O(n)
----------------------------------------------------
*/

class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string str : strs){
            ans = ans + to_string(str.length());
            ans = ans + '#';
            ans = ans+str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i = 0;
        while(i < s.size()){
           int j = i;
            while(s[j] != '#') 
                j++;

            int len = stoi(s.substr(i , j-i));
            string words = s.substr(j+1 , len);
            ans.push_back(words);
            
             i = j+1 + len;
        }
        return ans;
    }
};
