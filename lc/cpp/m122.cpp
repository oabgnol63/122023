#include <iostream>
#include <vector>
#include <set>
class Solution {
    public:
        int maxProfit(std::vector<int>& prices) {
            int l = prices.size();
            int dp[l];
            std::set<int> result;
            dp[0] = 0;
            for (int i = 1; i < l; i++) {
                dp[i] = std::max(dp[i-1] , dp[i-1] + prices[i] - prices[i-1]);
                result.insert(dp[i]);
            }
            return *result.rbegin();
        }
};

int main() {
    Solution a;
    std::vector<int> prices = {7,1,5,3,6,4};
    std::cout << a.maxProfit(prices);
}