/*
=========================================================
            Fibonacci using Dynamic Programming (DP)
=========================================================

What is Dynamic Programming (DP)?
---------------------------------
Dynamic Programming is an optimization technique used when
a problem has:

1. Overlapping Subproblems
   - The same subproblem is solved multiple times.
   - Example:
        fib(5)
       /      \
    fib(4)   fib(3)
    /   \      |
 fib(3) fib(2) ...
 Notice fib(3) is calculated more than once.

2. Optimal Substructure
   - The solution of a bigger problem can be built using
     the solutions of smaller subproblems.
   - Example:
        fib(n) = fib(n-1) + fib(n-2)

---------------------------------------------------------

What is Memoization?
--------------------
Memoization means storing the answer of a subproblem after
calculating it for the first time.

Next time, instead of solving it again, we simply return
the stored answer.

This avoids unnecessary recursive calls.

---------------------------------------------------------

Without DP:
------------
Time Complexity : O(2^n)
Space Complexity: O(n)  // recursion stack

With Memoization:
-----------------
Time Complexity : O(n)
Space Complexity: O(n)
    - O(n) for recursion stack
    - O(n) for storing computed answers

---------------------------------------------------------

Approach:
---------
1. If n is 0 or 1, return n.
2. Check if fib(n) is already stored in the map.
3. If yes, return the stored value.
4. Otherwise compute:
       fib(n) = fib(n-1) + fib(n-2)
5. Store the answer in the map.
6. Return it.

=========================================================
*/

class Solution {
public:

    // HashMap used for Memoization
    // Key   -> n
    // Value -> Fibonacci of n
    unordered_map<int, int> dp;

    int fib(int n) {

        // Base Case
        // fib(0) = 0
        // fib(1) = 1
        if (n <= 1)
            return n;

        // If already computed, return stored answer
        if (dp.find(n) != dp.end())
            return dp[n];

        // Compute current Fibonacci recursively
        int ans = fib(n - 1) + fib(n - 2);

        // Store the answer so future calls can reuse it
        dp[n] = ans;

        // Return the computed answer
        return ans;
    }
};