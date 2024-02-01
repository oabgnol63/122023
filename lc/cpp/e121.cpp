#include <iostream>
#include <vector>

class Solution {
    public:
        int maxProfit(std::vector<int>& prices) {
            int k = prices.size();
            int maxP = 0;
            int dp[k];
            dp[0] = 0;
            for (int j = 1; j < k; j++) {
                dp[j] =  dp[j-1] + prices[j] - prices[j-1];
                dp[j] = dp[j] > 0 ? dp[j] : 0;
                maxP = (dp[j] > maxP) ? dp[j] : maxP;
            }
            return (maxP > 0) ? maxP : 0;
        }
};

int main() {
    std::vector<int> prices= {7,1,5,3,6,4};
    Solution a;
    std::cout << a.maxProfit(prices);
}