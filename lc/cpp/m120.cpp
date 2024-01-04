#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int dp[triangle.size()][triangle.size()];
            set<int> result;
            dp[0][0] = triangle[0][0];
            if(triangle.size() == 1) return dp[0][0];
            for(int i = 1; i < triangle.size(); i++) {
                dp[i][0] = dp[i-1][0] + triangle[i][0];
                dp[i][triangle[i].size()-1] = dp[i-1][triangle[i-1].size()-1] +  triangle[i][triangle[i].size()-1];
                for(int j = 1; j < triangle[i].size()-1; j++) {
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
                }
            }
            for (auto x : dp[triangle.size() - 1]) {
                result.insert(x);
            }
            return *result.begin();

        }
};
int main() {
    Solution a;
    vector<vector<int>> test = {{-1}, {2,3}, {1,-1,-3}};
    cout << a.minimumTotal(test);
}