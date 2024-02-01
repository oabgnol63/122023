#include <iostream>
#include <bits/stdc++.h>

namespace m3 {
    class Solution {
        public: 
            bool isPalindrome(std::string s, int i ,int j) {
                while(i<j) {
                    if(s[i] != s[j]) {
                        return false;
                    }
                ++i; --j;
                }
                return true;
            }
            std::string longestPalindrome(std::string s) {
                if(s.size() == 0) return "";
                else if (s.size() == 1) return std::string(1,s[0]);
                else {
                    int a[s.size()];
                    int index = 0;
                    memset(a,0,sizeof(a));
                    for(auto& x : a) x = x + 1 ;
                    for(int i = 0; i < s.size() - 1; i++) {
                        for(int j = i+1; j < s.size(); j++) {
                            if(isPalindrome(s,i,j)) {
                                a[i] = std::max(a[i],j-i+1);
                            }
                        }
                        if(a[i] > a[index]) {
                            index = i;
                        }
                    }
                    return s.substr(index,a[index]);
                }
            }
    };
}
int main(int argc, char const *argv[])
{
    m3::Solution a;
    std::string s = "ac";
    std::cout << a.longestPalindrome(s);
    return 0;
}
