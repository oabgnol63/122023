#include <iostream>

class Solution {
    public:
        std::string rm_first_char(std::string s) {
            if(s == "" || s.length() == 1) return "";
            s = s.substr(1,s.length()-1);
            return s;
        }
        bool isInterleave(std::string s1, std::string s2, std::string s3) {\
            if(s3 == "" && (s1 != "" | s2 != "")) {
                return false;
            }
            if(s1 == "" && s2 == "" && s3 == "") {
                return true;
            }
            if(s3[0] == s1[0] && s3[0] != s2[0] ) {
                return isInterleave(rm_first_char(s1),s2,rm_first_char(s3));
            }
            else if(s3[0] == s2[0] && s3[0] != s1[0]) {
                return isInterleave(s1,rm_first_char(s2),rm_first_char(s3));
            }
            else if((s1[0] == s2[0]) && (s1[0] == s3[0])) {
                return isInterleave(rm_first_char(s1),s2,rm_first_char(s3)) | isInterleave(s1,rm_first_char(s2),rm_first_char(s3));
            }
            else 
                return false;
        }
};

int main() {
    Solution a;
    std::cout << a.isInterleave("abbbbbbcabbacaacccababaabcccabcacbcaabbbacccaaaaaababbbacbb","ccaacabbacaccacababbbbabbcacccacccccaabaababacbbacabbbbabc","cacbabbacbbbabcbaacbbaccacaacaacccabababbbababcccbabcabbaccabcccacccaabbcbcaccccaaaaabaaaaababbbbacbbabacbbacabbbbabc");
}