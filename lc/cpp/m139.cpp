#include <iostream>
#include <vector>

class Solution {
    public:
        bool bsearch(std::string s, std::vector<std::string>& wordDict) {
            for(int i = 0; i < wordDict.size(); i++) {
                if(wordDict[i] == s) return true;
            }
            return false;
        } 
        bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
            if(s.length() == 0) return true;
            for(int i = 0; i < s.length(); i++) {
                if(bsearch(s.substr(0,i), wordDict)) {
                    std::cout << "Continue searching for " << s.substr(i,s.length()-i) << "\n";
                    return wordBreak(s.substr(i,s.length()-i), wordDict);
                }
            }
            return false;
        }
};

int main() {
    std::vector<std::string> wordDict = {"leet", "code"};
    std::string s = "leetcode";
    Solution a;
    if(a.wordBreak(s,wordDict))
        std::cout << "True";
    else std::cout << "False";
}