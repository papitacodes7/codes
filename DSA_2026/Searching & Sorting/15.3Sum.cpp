#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
                else if (sum < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = sol.threeSum(nums);

    for (auto &triplet : result) {
        cout << "[ ";
        for (int x : triplet) cout << x << " ";
        cout << "]\n";
    }
    return 0;
}


// We first sort the array so that we can apply the two-pointer technique and easily handle duplicates. Then, we fix one element nums[i] and try to find two other elements after it whose sum is -nums[i], because nums[i] + nums[j] + nums[k] = 0. For this, we use two pointers: j starting from i + 1 and k starting from the end of the array. If the sum of the three numbers is 0, we store the triplet and move both pointers inward, skipping over duplicate values to avoid repeating the same triplet. If the sum is less than 0, we move j forward to increase the sum, and if the sum is greater than 0, we move k backward to decrease the sum. Sorting ensures that all triplets are generated in a structured way and duplicates are avoided efficiently.

// Time Complexity (TC):

// Sorting takes O(n log n)

// The outer loop runs O(n) times, and the two-pointer scan runs O(n) in total

// Overall TC: O(n²)

// Space Complexity (SC):

// Extra space used (excluding output): O(1)

// Output space depends on the number of valid triplets