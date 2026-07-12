// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.


class Solution {
    bool alphaNum(char c){
        return (
            c >= 'A' && c <= 'Z' ||
            c >= 'a' && c <= 'z' ||
            c >= '0' && c <= '9'
        );
    }
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;

        while(l < r){
            while(l < r && !alphaNum(s[l])){
                l++;
            }
            while(r > l && !alphaNum(s[r])){
                r--;
            }
            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++, r--;
        }
        return true;
    }
};