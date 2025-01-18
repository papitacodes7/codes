#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the lower bound of x in the array
    int lowerBound(vector<int> arr, int x) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] >= x) {
                ans = mid;
                // look for smaller index on the left
                high = mid - 1;
            }
            else {
                low = mid + 1; // look on the right
            }
        }
        return ans;
    }

    // Function to find the upper bound of x in the array
    int upperBound(vector<int> &arr, int x) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] > x) {
                ans = mid;
                // look for smaller index on the left
                high = mid - 1;
            }
            else {
                low = mid + 1; // look on the right
            }
        }
        return ans;
    }

    // Function to find the range of x in the array
    vector<int> searchRange(vector<int>& arr, int x) {
        int low = lowerBound(arr, x);
        int high = upperBound(arr, x);
        if (low == arr.size() || arr[low] != x) return {-1, -1};
        return {low, high - 1};
    }

    // Function to count the frequency of x in the array
    int countFreq(vector<int>& arr, int x) {
        vector<int> range = searchRange(arr, x);
        if (range[0] == -1) return 0;
        else return (range[1] - range[0] + 1);
    }
};