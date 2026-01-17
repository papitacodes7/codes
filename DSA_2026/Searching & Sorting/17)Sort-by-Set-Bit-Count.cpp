#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Comparator: returns true if a should come before b
    static bool cmp(int a, int b) {
        return __builtin_popcount(a) > __builtin_popcount(b);
    }

    // Function to sort array by set bit count
    void sortBySetBitCount(int arr[], int n) {
        stable_sort(arr, arr + n, cmp);
    }
};

int main() {
    int arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution obj;
    obj.sortBySetBitCount(arr, n);

    // Print result
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}


//Every integer can be represented in binary form, which consists only of 0s and 1s.
// In binary representation:

// a set bit means a bit with value 1

// an unset bit means a bit with value 0

// The number of set bits in a number tells us how many 1s are present in its binary representation.
// In this problem, we need to sort the array such that numbers having more set bits (1s) appear first.

// To count the number of set bits efficiently, we use the built-in function __builtin_popcount(x), which returns the count of 1s in the binary form of x.

// While sorting, we compare two elements and place the element with a higher set bit count before the other. If two elements have the same number of set bits, the problem requires that their original relative order should be preserved. Therefore, we use stable_sort, which maintains the order of equal elements.

// Although C++ allows writing the comparison logic using a lambda function (the syntax that looks like [](int a, int b) { ... }), it can be confusing for beginners. Hence, instead of using a lambda, we define a separate static comparison function (static bool cmp), which performs the same task in a clearer and more readable way.

// ⏱️ Time Complexity (TC)

// stable_sort takes O(n log n) time

// Each comparison uses __builtin_popcount, which works in O(1)