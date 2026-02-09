#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int low = 0;
        int high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= arr[high]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low; // index of minimum element
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.findKRotation(arr) << endl;

    return 0;
}


// minimum element ka inndex return krna he.. that's it.. aaj he 9/2/26.. bst ka video dekhna tha reh gya.. so kal try krta isiliye aaj ka potd krdiya jo yehi he... alright peace


//Intuition

// In a sorted array, the minimum element is always at index 0. When the array is rotated k times, the sorted order breaks at exactly one point, and the minimum element shifts to index k. Hence, the number of rotations is equal to the index of the minimum element. To find this efficiently, we use binary search. At each step, we compare arr[mid] with arr[high] to identify the sorted and unsorted halves. The minimum element can only lie in the unsorted part or at mid itself. If arr[mid] <= arr[high], the right half is sorted, so the minimum lies in the left half (or at mid), and we move high = mid. Otherwise, the minimum lies in the right half, so we move low = mid + 1. The process continues until low == high, which gives the index of the minimum element, i.e., the rotation count.

// Time Complexity

// O(log N) — binary search reduces the search space by half each iteration.

// Space Complexity

// O(1) — only constant extra space is used.
