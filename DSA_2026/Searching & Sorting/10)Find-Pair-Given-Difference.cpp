#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        int i = 0, j = 1;
        sort(arr.begin(), arr.end());
        
        while (i < arr.size() && j < arr.size()) {
            if (i != j && arr[j] - arr[i] == x)
                return true;
            else if (arr[j] - arr[i] < x)
                j++;
            else
                i++;
        }
        return false;
    }
};

int main() {
    int n, x;
    cin >> n >> x;          // size of array and difference

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << (obj.findPair(arr, x) ? "true" : "false");

    return 0;
}



////The idea is to first sort the array so that the difference between elements becomes predictable as we move forward. After sorting, we use two pointers i and j, where i points to the smaller element and j points to a larger one. We calculate arr[j] - arr[i]: if it equals x, we return true; if it is smaller than x, we move j forward to increase the difference; if it is greater than x, we move i forward to decrease the difference. This way, we check all valid pairs efficiently without nested loops. The time complexity is O(n log n) due to sorting, while the two-pointer traversal runs in O(n), and the space complexity is O(1) auxiliary space since no extra data structures are used.