#include <iostream>
#include <set>
class Solution {
    public: 
        int minDistance(std::string word1, std::string word2) {
            int m = word1.length();
            int n = word2.length();
            std::set<int> threesome;
            int subtitutionCost = 0;
            const char *cword1 = word1.c_str();
            const char *cword2 = word2.c_str();
            int dp[m+1][n+1];
            for(int j = 0; j<=n; j++) {
                dp[0][j] = j;
                std::cout << dp[0][j] << " ";
            }
            std::cout << "\n";
            for(int i = 0; i <= m; i++) {
                dp[i][0] = i;
                std::cout << dp[i][0] << " ";
            }
            std::cout << "\n";
            for(int j = 1; j<=n; j++) {
                for(int i = 1; i<=m; i++) {
                    if(*(cword1 + i - 1) == *(cword2 + j - 1) ) {
                        subtitutionCost = 0;
                    }
                    else subtitutionCost = 1;
                    threesome.insert(dp[i-1][j]+1);
                    threesome.insert(dp[i][j-1]+1);
                    threesome.insert(dp[i-1][j-1]+subtitutionCost);
                    dp[i][j] = *threesome.begin();
                    std::cout << *threesome.begin() << " ";
                    threesome.clear();
                }
                std::cout << "\n";
            }
            return dp[m][n];
        }
};

int main() {
    Solution a;
    std::cout << a.minDistance("horse", "ros");
}