#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Target found
            if (arr[mid] == x)
                return mid;

            // Left half is sorted
            if (arr[low] <= arr[mid]) {
                if (arr[low] <= x && x <= arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (arr[mid] <= x && x <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    Solution obj;
    cout << obj.search(arr, target) << endl;

    return 0;
}

// Intuition:
// Basically, we apply binary search but with a few extra checks because the array is a sorted array that has been rotated once. At every step, we first check if the middle element itself is the target. If not, we determine which half of the array is sorted—left or right—since in a rotated sorted array, at least one half is always sorted. Once the sorted half is identified, we check whether the target lies within the range of that sorted half (between low and mid or between mid and high). If the target lies in that range, we continue the search in that half; otherwise, we discard it and search in the other half. This way, in each iteration, half of the array is eliminated, maintaining the efficiency of binary search while correctly locating the target.

// Time Complexity:
// O(log n) — because the search space is reduced to half in every iteration.

// Space Complexity:
// O(1) — only constant extra space is used.
