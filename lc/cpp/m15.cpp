#include <iostream>
#include <set>
#include <vector>
#include <bits/stdc++.h>
class Solution {
    public:
        std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
            std::set<std::vector<int>> st;
            std::vector<std::vector<int>> result;
            std::sort(nums.begin(),nums.end());
            for(int i = 0; i<nums.size()-2; i++) {
                int j = i + 1, k = nums.size() - 1;
                while(j < k) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        std::vector temp = {nums[i], nums[j], nums[k]};
                        st.insert(temp);
                        j++; k--;
                    } else if(nums[i]+nums[j]+nums[k] < 0) {
                        j++;
                    } else {
                        k--;
                    }
                }
            }
            for(auto x : st) {
                result.push_back(x);
            }
            return result;
    }
};

int main() {
    Solution a;
    std::vector<int> nums = {-1,0,1,2,-1,4};
    //for(auto x : nums) std::cout << x << " ";
    std::vector<std::vector<int>> result = a.threeSum(nums);
    for(auto x : result) {
        for(auto y : x) {
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
}