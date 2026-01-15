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
