#include <iostream>
#include <stack>
#include <cmath>

#include <iostream>
#include <stack>
#include <cmath>

class Solution {
    public:
    int pos_x = 0;
    int reverse(int x) {
        if(x==0) return 0;
        int pos_x = x;

        std::stack<int> st;
        int result = 0, k = 0;
        while(abs(pos_x)>0) {
            st.push(pos_x%10);
            pos_x=pos_x/10;
        }
        k = st.size();
        for(int i = 0;i<k;i++) {
            try {
                result += st.top() * pow(10,i);
                st.pop();
            } catch(std::runtime_error& e) {
                std::cerr << e.what() << std::endl;
            }          
        }
        return result;
    }
};

int main() {
    Solution *a = new Solution;
    std::cout << a->reverse(1563847412222222);
}