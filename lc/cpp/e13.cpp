#include <iostream>
#include <map>

class Solution {
    private:
        std::map<char,int> mp{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M',1000}};
    public: 
        int romanToInt(std::string s) {
            int result = mp[s[s.size()-1]];
            for(int i = s.size() - 2; i>=0; i--) {
                if(mp[s[i]] >= mp[s[i+1]]) {
                    result += mp[s[i]];
                } else {
                    result -= mp[s[i]];
                }
            }
            return result;
        }
};

int main() {
    Solution a;
    std::cout << a.romanToInt("XVIII");
}