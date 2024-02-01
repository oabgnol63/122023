#include <iostream>

class Solution {
    public:
        bool hasSubsetSum(int sum, int set[], int n) {
            bool tab[n+1][sum+1];
            for(int i = 0;i<=n;i++) {
                tab[i][0] = true;
            }
            for(int j=1;j<=sum;j++) {
                tab[0][j] = false;
            }
            for(int i=1; i<=n;i++) {
                for(int j=1; j<=sum;j++) {
                    if(j<set[i-1]) {
                        tab[i][j] = tab[i-1][j];
                    }
                    else tab[i][j] = tab[i-1][j] || tab[i-1][j-set[i-1]];
                }
            }
            return tab[n][sum];
        }
};



int main(int argc, char const *argv[])
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 100;
    int n = sizeof(set) / sizeof(set[0]);
    Solution a;
    if (a.hasSubsetSum(sum, set, n) == true)
        std::cout << "Found a subset with given sum";
    else
        std::cout << "No subset with given sum";
    return 0;
}
