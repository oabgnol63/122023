#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
class Solution {
    public:
        int evalRPN(std::vector<std::string> &token) {
            std::stack<int> _st;
            for(int i = 0; i<token.size(); i++) {
                if(token[i] == "+") {
                    int temp = _st.top();
                    _st.pop();
                    temp += _st.top();
                    _st.pop();
                    _st.push(temp);
                } else if(token[i] == "-") {
                    int temp = _st.top();
                    _st.pop();
                    temp = _st.top() - temp;
                    _st.pop();
                    _st.push(temp);                    
                } else if(token[i] == "*") {
                    int temp = _st.top();
                    _st.pop();
                    temp *= _st.top();
                    _st.pop();
                    _st.push(temp);
                } else if(token[i] == "/") {
                    int temp = _st.top();
                    _st.pop();
                    temp = _st.top() / temp;
                    _st.pop();
                    _st.push(temp);
                } else {
                    _st.push(std::stoi(token[i]));
                }
            }
            return _st.top();
        }
};

int main() {
    Solution a;
    std::vector<std::string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    std::cout << a.evalRPN(tokens);
}