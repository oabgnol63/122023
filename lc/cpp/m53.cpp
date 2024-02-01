#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
    public:
        int maxSubArray(std::vector<int>& nums) {
            std::vector<int> max;
            max.push_back(nums[0]);
            for (int i = 1; i<nums.size();i++) {
                max.push_back( std::max(nums[i],max[i-1]+nums[i]));
            }
            int s_end = max_element(begin(max), end(max)) - begin(max);
            int s_begin = 0;
            for(int i = 0; i<s_end; i++) {
                if(nums[i] == max[i]) {
                    s_begin = i;
                }
            }
            return *max_element(begin(max), end(max));
        }   
};

int main() {
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution a;
    int b = a.maxSubArray(nums);
    std::cout << b;
}