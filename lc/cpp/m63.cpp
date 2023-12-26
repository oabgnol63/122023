#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        dp[0][0] = !obstacleGrid[0][0];
        for(int j=1; j<n; j++) {
            if(dp[0][j-1]==0||obstacleGrid[0][j]==1) {
                dp[0][j] = 0;
            } else
                dp[0][j] = 1;
        }
        if(m==1) return dp[0][n-1];
        for(int i = 1; i<m;i++) {
            if(dp[i-1][0]==0||obstacleGrid[i][0]==1) {
                dp[i][0] = 0;
            } else
            dp[i][0] = 1;
        }
        if(n==1) return dp[m-1][0];
        for(int i=1; i<m;i++) {
            for(int j=1; j<n;j++) {
                if(!obstacleGrid[i][j]) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
        cout << !0;
}