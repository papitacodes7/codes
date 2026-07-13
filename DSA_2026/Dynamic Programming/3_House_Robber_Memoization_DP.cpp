#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
=========================================================
              House Robber (Memoization)
=========================================================

Problem:
--------
A robber wants to steal money from houses arranged in a line.

Constraint:
-----------
Two adjacent houses cannot be robbed.

Approach:
---------
State:
solve(i, free)

i    -> Current house index.

free -> Can we rob the current house?

free = 1
    We are allowed to rob this house.

free = 0
    Previous house was robbed,
    so this house must be skipped.

Choices:
--------
If free == 0
    Skip current house.

If free == 1
    1. Rob current house.
    2. Skip current house.

Return the maximum of both choices.

Time Complexity : O(n)
Space Complexity: O(n)

=========================================================
*/

class Solution {
public:

    int solve(vector<int>& nums, int i, int free,
              vector<vector<int>>& dp) {

        // No houses left
        if (i == nums.size())
            return 0;

        // Return stored answer if already computed
        if (dp[i][free] != -1)
            return dp[i][free];

        // Can't rob this house because the previous one was robbed
        if (free == 0) {
            return dp[i][free] = solve(nums, i + 1, 1, dp);
        }

        // Option 1: Rob current house
        int take = nums[i] + solve(nums, i + 1, 0, dp);

        // Option 2: Skip current house
        int skip = solve(nums, i + 1, 1, dp);

        // Store and return the better choice
        return dp[i][free] = max(take, skip);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        // dp[i][free]
        // i     -> Current house
        // free  -> Whether we can rob the current house
        vector<vector<int>> dp(n, vector<int>(2, -1));

        // Start from the first house.
        // Initially we are free to rob.
        return solve(nums, 0, 1, dp);
    }
};

int main() {

    Solution obj;

    int n;
    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter money in each house:\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Maximum money robbed = " << obj.rob(nums);

    return 0;
}

