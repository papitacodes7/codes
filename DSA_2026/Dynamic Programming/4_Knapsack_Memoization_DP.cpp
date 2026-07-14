// i
// nt fun(vector <int> &val, vector <int> &wt, int n, int i, int cap){
//     if (i == n) return 0; // iska mtlb kuch nhi kr skte last me pohnch gye #sraitem khatam hogya
//     if (wt[i] > cap) fun (val, wt, n, i + 1, cap); // if weight zyda hoga than capacity toh obviously usse nhi lenge.. naa hi usse le skte hein..

//     int yes = val[i] + fun( val, wt, n, i + 1, cap - wt[i]); // jo bhi iss item ka weight he woh iss capacity se minus hoga
//     int no = fun( val, wt, n, i + 1, cap);

//     return max ( yes, no );     
// }
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int fun(vector<int> &val, vector<int> &wt, int n, int i, int cap,
            vector<vector<int>> &dp) {

        // Base case
        // Agar saare items dekh liye (i last tak pahunch gaya),
        // toh ab aur kuch nahi le sakte.
        if (i == n)
            return 0;

        // Memoization
        // Agar is (i, cap) combination ka answer pehle se calculate hai,
        // toh wahi return kar do.
        if (dp[i][cap] != -1)
            return dp[i][cap];

        // Agar current item ka weight capacity se zyada hai,
        // toh is item ko le hi nahi sakte.
        // Isliye sirf next item par chale jao.
        if (wt[i] > cap)
            return dp[i][cap] = fun(val, wt, n, i + 1, cap, dp);

        // YES -> Current item ko le lo.
        // Iska value add hoga aur capacity kam ho jayegi.
        int yes = val[i] + fun(val, wt, n, i + 1, cap - wt[i], dp);

        // NO -> Current item ko mat lo.
        // Capacity same rahegi.
        int no = fun(val, wt, n, i + 1, cap, dp);

        // Dono options me jo maximum value dega,
        // wahi answer store karke return kar do.
        return dp[i][cap] = max(yes, no);
    }

    int knapsack(int cap, vector<int> &val, vector<int> &wt) {

        int n = val.size();

        // 2D DP Table
        // dp[i][cap] = maximum value we can get
        // starting from index i with remaining capacity = cap.

        vector<vector<int>> dp(n + 1, vector<int>(cap + 1, -1));

        return fun(val, wt, n, 0, cap, dp);
    }
};

int main() {

    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int cap = 50;

    Solution obj;

    cout << "Maximum Value = " << obj.knapsack(cap, val, wt);

    return 0;
}