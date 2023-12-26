#include <iostream>
#include <vector>

class Solution {
    public:
        void dfs(int left, int right, std::string s, std::vector<std::string> *result, int n) {
            if(s.length()==n*2) {
                result->push_back(s);
                return;
            }
            if(left<n) {
                //s+="("; Wrong
                dfs(left+1,right,s + "(", result,n);
            }
            if(right<left) {
                //s+=")"; Wrong
                dfs(left,right+1,s + ")", result,n);
            }
        }
        std::vector<std::string> generateParenthesis(int n) {
            std::string s = "";
            std::vector<std::string> result;
            dfs(0,0,s,&result,n);
            return result;
        }
};

int main(int argc, char const *argv[])
{
    Solution a;
    std::vector<std::string> exam = a.generateParenthesis(3);
    for(auto x : exam) std::cout << x << " ";
    return 0;
}


