#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &arr) {
        int left = 1, right = 1;
        int n = arr.size();

        int maxLeft = INT_MIN, maxRight = INT_MIN;

        // Traverse from left to right
        for (int i = 0; i < n; i++) {
            left *= arr[i];
            maxLeft = max(maxLeft, left);

            if (left == 0)
                left = 1;
        }

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            right *= arr[i];
            maxRight = max(maxRight, right);

            if (right == 0)
                right = 1;
        }

        return max(maxLeft, maxRight);
    }
};

int main() {
    Solution sol;

    vector<int> arr = {2, 3, -2, 4};
    cout << "Maximum Product Subarray: " << sol.maxProduct(arr) << endl;

    return 0;
}


// LL ke questions aaj karne ke bajay sirf **POTD (Maximum Product Subarray)** solve kiya.  today's date is.. 8/2/26
