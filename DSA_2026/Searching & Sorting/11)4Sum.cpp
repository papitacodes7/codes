#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
        vector<vector<int>> ans;
        int n = arr.size();
        
        if (n < 4) return ans;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && arr[j] == arr[j - 1]) continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    long long sum = 1LL * arr[i] 
                                  + arr[j] 
                                  + arr[k] 
                                  + arr[l];

                    if (sum == target) {
                        ans.push_back({arr[i], arr[j], arr[k], arr[l]});

                        while (k < l && arr[k] == arr[k + 1]) k++;
                        while (k < l && arr[l] == arr[l - 1]) l--;

                        k++;
                        l--;
                    }
                    else if (sum < target) {
                        k++;
                    }
                    else {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = sol.fourSum(arr, target);

    for (auto &quad : result) {
        cout << "[ ";
        for (int x : quad) cout << x << " ";
        cout << "]\n";
    }
    return 0;
}


// To solve the 4Sum problem efficiently, we first sort the array so that we can systematically fix elements and use the two-pointer technique while also avoiding duplicates. We fix the first element using index i and the second element using index j, then search for the remaining two elements using two pointers k (from j+1) and l (from the end). Because the array is sorted, if the current sum of four elements is smaller than the target, we move k forward to increase the sum; if it is larger, we move l backward to decrease it. Whenever a valid quadruplet is found, we store it and skip over duplicate values to ensure uniqueness. Casting the sum calculation to long long prevents integer overflow when dealing with large values.

// Time Complexity (TC)

// Sorting the array: O(n log n)

// Two nested loops and a two-pointer scan: O(n³)

// Overall TC: O(n³)

// Space Complexity (SC)

// Extra space used (excluding output): O(1)

// Output space depends on the number of valid quadruplets found