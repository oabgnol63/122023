#include <iostream>
#include <vector>

class Solution {
    private: 
        std::vector<std::vector<std::string>> concat_vector_of_string_vector(std::vector<std::vector<std::string>> input, std::vector<std::vector<std::string>> result) {
            for(auto x : input[0]) {
                std::vector<std::string> temp;
                temp.push_back(x);
                result.push_back(temp);
            }
            for(int j = 1; j < input.size(); j++) {
                int loop = result.size();
                int start = 0;
                while(start < loop) {
                    int len = 0;
                    for(auto z : result[start]) {
                        len += z.length();
                    }
                    if( len <= j) {
                        for(auto x : input[j]) {    
                            std::vector<std::string> temp = result[start];            
                            temp.push_back(x);
                            result.push_back(temp);
                            }
                        result.erase(result.begin() + start);
                        loop--;
                        }
                    else {
                        start++;
                    }
                }
                // std::cout << "Loop " << j << " \n";
                // // for(auto x : result) {
                // //     std::cout << "{ ";
                // //     for(auto y : x) {
                // //         std::cout << y << ",";
                // //     }
                // //     std::cout << " }\n";  
                // // }
                // // std::cout << "--------------------\n";
            }
            std::cout << result.size();
            return result;
        }
        bool is_palindrome(std::vector<std::vector<bool>> &dp, int i, int j, std::string &s){
            if(i == j){
                return dp[i][j] = true;
            }
            if(j-i == 1){
                if(s[i] == s[j]){
                    return dp[i][j] = true;
                }
                else{
                    return dp[i][j] = false;
                }
            }
            if(s[i] == s[j] && dp[i+1][j-1] == true){
                return dp[i][j] = true;
            } else {
                return dp[i][j] = false;
            }
        }

        std::vector<std::vector<std::string>> get_all_palindrome_sub_string(std::string s) {
            int n = s.size();
            std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
            std::vector<std::vector<std::string>> all_palindrome_vector;
            for(int g=0; g<n; g++){
                for(int i=0, j=g; j<n; i++, j++){
                    is_palindrome(dp, i, j, s);
                }
            }
            for(int i = 0; i < n; i++) {
                std::vector<std::string> temp;
                for(int j = 0; j < n; j++) {
                    if(dp[i][j] == true) {
                        temp.push_back(s.substr(i,j-i+1));
                    }
                }
                all_palindrome_vector.push_back(temp);
                // std::cout << "Loop " << i << " \n";
                // for(auto x : all_palindrome_vector) {
                //     std::cout << "{ ";
                //     for(auto y : x) {
                //         std::cout << y << ",";
                //     }
                //     std::cout << " }\n";  
                // }
                // std::cout << "--------------------\n";
            }
                
            return all_palindrome_vector;
        }
    public:
        std::vector<std::vector<std::string>> partition(std::string s) {
                std::vector<std::vector<std::string>> result;
                std::vector<std::vector<std::string>> input;
                input = get_all_palindrome_sub_string(s);
                result = concat_vector_of_string_vector(input, result);
                return result;
        }
};

int main() {
    Solution a;
    std::vector<std::vector<std::string>> result;
    a.partition("fffffffffffffff");
}