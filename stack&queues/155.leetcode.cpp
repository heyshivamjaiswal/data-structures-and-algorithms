class MinStack {
public:
   
   stack<int>st;
    MinStack() {
        
    }
    
    void push(int value) {
      st.push(value);  
    }
    
    void pop() {
       st.pop(); 
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int>temp = st;
        int mini = INT_MAX;

        while(!temp.empty()){
            mini = min(mini , temp.top());
            temp.pop();
        }
        return mini;
    }
};


// Push → Store (value, current minimum).
// Pop → Reveal the previous snapshot.
// getMin() → Read the second value of the top pair.


class MinStack {
public:
  

   stack<pair<int , int>>st;

    MinStack() {
        
    }
    
    void push(int value) {
       if(st.empty()){
        st.push({value , value});
       } 
       else{
        int currentMin = min({value , st.top().second});
        st.push({value , currentMin});
       }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

