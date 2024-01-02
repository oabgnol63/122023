#include <iostream>
#include <set>

class Solution {
    public:
        int ctoi(char numc) {
            return numc - '0';
        }
        int numDecodings(std::string s) {
                if(s[0] == '0') return 0;
                if(s.length() == 1 ) return 1;
                int dp[s.length()];
                if(ctoi(s[s.length()-1]) > 0) 
                    dp[s.length()-1] = 1;
                else 
                    dp[s.length()-1] = 0;
                if (ctoi(s[s.length()-2]) == 0)
                    dp[s.length()-2] = 0;
                else if (ctoi(s[s.length()-2])*10 + ctoi(s[s.length()-1]) > 0 && ctoi(s[s.length()-2])*10 + ctoi(s[s.length()-1]) <= 26) 
                    dp[s.length()-2] = dp[s.length()-1] + 1;
                else 
                    dp[s.length()-2] = dp[s.length()-1];
                //std::cout << dp[s.length()-2] << " " << dp[s.length()-1] << " ";
                for(int i = s.length() -3; i >= 0; i--) {
                    if(ctoi(s[i]) == 0 ) {
                        dp[i] =  0;
                    }
                    else if (ctoi(s[i])*10 + ctoi(s[i+1]) > 0 && ctoi(s[i])*10 + ctoi(s[i+1]) <= 26)
                        dp[i] = dp[i+1] + dp[i+2];

                    else 
                        dp[i] = dp[i+1];
                    //std::cout << dp[i] << " ";
                }
                return dp[0];
        }
};
int main() {
    // std::set<int> s;
    // int nums[] = {1,3,7,4,9,2};
    // int i = 0;
    // int k = 4;
    // while(*(nums+i) != '\0' ) {
    //     std::cout << nums[i] << " ";
    //     s.insert(nums[i]);
    //     if(s.size()>k)
    //         s.erase(*s.rbegin());
    //     ++i;
    // }
    // std::cout << "\n" << *s.rbegin();
    // return *s.rbegin();
    Solution a;
    std::cout << "\n" << a.numDecodings("2839");
}