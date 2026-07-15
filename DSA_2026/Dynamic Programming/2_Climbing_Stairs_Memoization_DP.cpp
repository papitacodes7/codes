#include <iostream>
#include <unordered_map>
using namespace std;

/*
=========================================================
         Climbing Stairs using Dynamic Programming
                  (Top-Down + Memoization)
=========================================================

Problem:
--------
You are climbing a staircase with 'n' steps.

At every move, you can either:
1. Climb 1 step
2. Climb 2 steps

Return the total number of distinct ways to reach the top.

---------------------------------------------------------

Why Dynamic Programming?
------------------------
This problem has two important DP properties:

1. Overlapping Subproblems
   - The same subproblems are solved repeatedly.

   Example:
        climb(5)
        /      \
   climb(4)   climb(3)
    /   \        |
 climb(3) climb(2)...

Notice that climb(3) is computed multiple times.

---------------------------------------------------------

2. Optimal Substructure
------------------------
The answer for a larger problem depends on smaller problems.

To reach step n,
the last move must have come from:

- Step (n-1) by taking 1 step
OR
- Step (n-2) by taking 2 steps

Therefore,

ways(n) = ways(n-1) + ways(n-2)

This is exactly the Fibonacci recurrence.

---------------------------------------------------------

What is Memoization?
--------------------
Memoization means storing the answer after computing it
for the first time.

Whenever the same subproblem appears again,
we simply return the stored answer instead of solving it
again.

---------------------------------------------------------

Base Cases
----------

n = 1
Only one way:
1

Answer = 1

n = 2
Two ways:
1 + 1
2

Answer = 2

---------------------------------------------------------

Time Complexity
---------------
Without DP:
O(2^n)

With Memoization:
O(n)

---------------------------------------------------------

Space Complexity
----------------
O(n)

- O(n) recursion stack
- O(n) hashmap

=========================================================
*/

class Solution {
public:

    // HashMap used for Memoization
    // Key   -> step number
    // Value -> number of ways to reach that step
    unordered_map<int, int> dp;

    int climbStairs(int n) {

        // Base Cases
        if (n <= 2)
            return n;

        // If already solved, return stored answer
        if (dp.find(n) != dp.end())
            return dp[n];

        // Compute recursively
        int ans = climbStairs(n - 1) + climbStairs(n - 2);

        // Store result for future use
        dp[n] = ans;

        return ans;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter number of stairs: ";
    cin >> n;

    cout << "Number of distinct ways = "
         << obj.climbStairs(n);

    return 0;
}

//iska tabulation..
class Solution {
public:
    int climbStairs(int n) {

        // Base cases
        if (n == 1 || n == 2)
            return n;

        // Pehle ka Pehla (ways to reach 1st stair)
        int prev2 = 1;

        // Pehla (ways to reach 2nd stair)
        int prev1 = 2;

        // Build answers from stair 3 to n
        for (int i = 3; i <= n; i++) {

            // Current answer
            int curr = prev1 + prev2;

            // Jo pehle hai woh pehle ka pehla ban jaaye
            prev2 = prev1;

            // Jo answer hai woh pehla ban jaaye
            prev1 = curr;
        }

        // Final answer(So prev1 is always one step ahead, holding the most recent DP value. By the time the loop ends, the most recent value is ways(n), so returning prev1 gives the correct answer.)
        return prev1;
    }
};class Solution {
public:
    int climbStairs(int n) {

        // Base cases
        if (n == 1 || n == 2)
            return n;

        // Pehle ka Pehla (ways to reach 1st stair)
        int prev2 = 1;

        // Pehla (ways to reach 2nd stair)
        int prev1 = 2;

        // Build answers from stair 3 to n
        for (int i = 3; i <= n; i++) {

            // Current answer
            int curr = prev1 + prev2;

            // Jo pehle hai woh pehle ka pehla ban jaaye
            prev2 = prev1;

            // Jo answer hai woh pehla ban jaaye
            prev1 = curr;
        }

        // Final answer(So prev1 is always one step ahead, holding the most recent DP value. By the time the loop ends, the most recent value is ways(n), so returning prev1 gives the correct answer.)
        return prev1;
    }
};