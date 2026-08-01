// • Opening brackets wait → Push them.
// • Closing brackets must match the stack top.
// • Wrong match or empty stack → Invalid.
// • After processing everything, the stack must be empty.

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char ch : s){

            // Opening bracket → wait for its closing bracket
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }

            // Closing bracket
            else{

                // No opening bracket available
                if(st.empty())
                    return false;

                // Top must be the matching opening bracket
                if((ch == ')' && st.top() != '(') ||
                   (ch == ']' && st.top() != '[') ||
                   (ch == '}' && st.top() != '{')){
                    return false;
                }

                // Pair matched
                st.pop();
            }
        }

        // All opening brackets should be matched
        return st.empty();
    }
};