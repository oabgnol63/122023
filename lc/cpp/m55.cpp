#include <iostream>
#include <vector>

class Solution {
    public:
        bool canJump(std::vector<int> nums) {
            if(nums.size()==1) return true;
            std::vector<int> dp(nums.size()-1);
            for(int i = 0; i<nums.size()-1; i++) {
                if(i==0) {
                    dp[i] = nums[i];
                }
                else {
                    dp[i] = std::max(nums[i] + i,dp[i-1]);
                }
                if(dp[i] >= nums.size()-1) return true;
                if(dp[i] == i) return false;
            }
            return false;
        }
};

int main() {
    Solution a;
    std::vector<int> nums = {1,0,1,0};
    std::cout << a.canJump(nums);
}