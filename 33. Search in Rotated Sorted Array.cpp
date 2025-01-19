#include <bits/stdc++.h>
using namespace std;
    class Solution {
        public:
    int search(vector<int>& arr, int x) {
        int low = 0, high = arr.size() - 1; // Initialize pointers for binary search
        while (low <= high) { // Continue searching while the range is valid
            int mid = (low + high) / 2; // Find the mid index
            if (arr[mid] == x) return mid; // If the middle element is the target, return its index

            if (arr[low] <= arr[mid]) { // Check if the left half is sorted
                if (arr[low] <= x && x <= arr[mid]) { // If the target is within the range of the sorted left half
                    high = mid - 1; // Narrow down to the left half
                } else {
                    low = mid + 1; // Narrow down to the right half
                }
            } else { // Otherwise, the right half must be sorted
                if (arr[mid] <= x && x <= arr[high]) { // If the target is within the range of the sorted right half
                    low = mid + 1; // Narrow down to the right half
                } else {
                    high = mid - 1; // Narrow down to the left half
                }
            }
        }
        return -1; // Return -1 if the target is not found
    }
};
