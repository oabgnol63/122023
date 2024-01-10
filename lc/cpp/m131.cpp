#include <iostream>
#include <vector>

class Solution {
    public: 
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
                std::cout << "Loop " << j << " \n";
                for(auto x : result) {
                    std::cout << "{ ";
                    for(auto y : x) {
                        std::cout << y << ",";
                    }
                    std::cout << " }\n";  
                }
                std::cout << "--------------------\n";
            }
            return result;
        }
};

int main() {
    std::vector<std::vector<std::string>> result;
    std::vector<std::vector<std::string>> a = { {"a","aa","aabaa"}, {"a","aba"}, {"b","baab"}, {"a", "aa"}, {"a"}, {"b"} };
//     for(auto x : a[0]) {
//         std::vector<std::string> temp;
//         temp.push_back(x);
//         result.push_back(temp);
//     }
//     for(int j = 1; j < a.size(); j++) {
//         int loop = result.size();
//         int start = 0;

//         while(start < loop) {
//             int len = 0;
//             for(auto z : result[start]) {
//                 len += z.length();
//             }
//             if( len <= j) {
//                 for(auto x : a[j]) {    
//                     std::vector<std::string> temp = result[start];            
//                     temp.push_back(x);
//                     result.push_back(temp);
//                     }
//                 result.erase(result.begin() + start);
//                 loop--;
//                 }
//             else {
//                 start++;
//             }
//         }
//         std::cout << "Loop " << j << " \n";
//         for(auto x : result) {
//             std::cout << "{ ";
//         for(auto y : x) {
//             std::cout << y << ",";
//         }
//         std::cout << " }\n";
        
//     }
//     std::cout << "--------------------\n";
// }
    Solution z;
    z.concat_vector_of_string_vector(a, result);

}