
// • Number → Push.
// • Operator → Pop two numbers.
// • Compute: operand1 operator operand2.
// • Push result back.

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(string token : tokens){
            //operator
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                if(token == "+") st.push(a+b);
                else if (token == "-") st.push(a-b);
                else if (token == "*") st.push(a*b);
                else st.push(a/b);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }