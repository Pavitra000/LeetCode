class Solution {
public:
    bool isValid(string s) {

        stack<int> stack;
        for(auto it : s){
            if(stack.empty()==1){stack.push(it);}
            else if(stack.top()=='(' && it==')' || stack.top()=='{' && it=='}' || stack.top()=='[' && it==']'){stack.pop();}
            else{stack.push(it);}
        }
        if(stack.empty()==1){return true;}
        return false;
    }
};