#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long num = n;
        if (x == 0){
            return 0;
        }
        if (num == 0){
            return 1;
        }
        if (num < 0){
            num = -num;
        }
        while (num > 0){
            if (num % 2 == 1){
                ans *= x;
            }
            x *= x;
            num = num / 2;
        }
        if (n < 0){
             ans = 1 / ans;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.myPow(2.00000, 10) << endl; // 1024.00000
    cout << sol.myPow(2.10000, 3) << endl;  // 9.26100
    cout << sol.myPow(2.00000, -2) << endl; // 0.25000
    return 0;
}
