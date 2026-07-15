#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {

        /*
        ============================================================
                    FIBONACCI - TABULATION (BOTTOM-UP DP)
        ============================================================

        Fibonacci Series:
        fib(0) = 0
        fib(1) = 1

        fib(n) = fib(n-1) + fib(n-2)

        ============================================================
        HOW WE REACHED TABULATION?
        ============================================================

        1) RECURSION

        We first solve Fibonacci using recursion.

            fib(5)
           /     \
        fib(4)   fib(3)
        /   \      /   \
      fib(3) fib(2) ...

        Notice:
        fib(3), fib(2) etc. are calculated multiple times.

        This creates lots of repeated work.

        ------------------------------------------------------------

        2) MEMOIZATION (TOP-DOWN DP)

        To avoid recalculating the same answer, we store it
        inside a DP array.

        Before solving a problem, we check:

            if(dp[n] != -1)
                return dp[n];

        If the answer already exists,
        simply return it instead of solving again.

        This is called Memoization because
        we "remember" previously computed answers.

        Why Top-Down?

        We start from the biggest problem (fib(n))
        and recursively move towards smaller problems.

                fib(5)
                  |
                fib(4)
                  |
                fib(3)
                  |
                fib(2)
                  |
             fib(1), fib(0)

        Although Memoization removes repeated calculations,
        it still uses recursion.

        Every recursive call creates a function call,
        which consumes stack memory and adds overhead.

        ============================================================
        WHY TABULATION?
        ============================================================

        Instead of solving recursively,

        We solve iteratively.

        Instead of asking
        "What is fib(5)?"

        We ask

        "Let's calculate fib(0),
         then fib(1),
         then fib(2),
         then fib(3)..."

        until we reach fib(n).

        No recursion.
        No function call overhead.
        No recursion stack.

        This approach is called
        TABULATION or BOTTOM-UP DP.

        ============================================================
        TABULATION IDEA
        ============================================================

        Step 1:
        Store the known answers.

            dp[0] = 0
            dp[1] = 1

        Step 2:
        Build all future answers using previous answers.

            dp[2] = dp[1] + dp[0]
            dp[3] = dp[2] + dp[1]
            dp[4] = dp[3] + dp[2]
            ...

        ============================================================
        DRY RUN (n = 6)

        Initially

        Index : 0 1 2 3 4 5 6
        DP    : 0 1 _ _ _ _ _

        i = 2

        dp[2] = dp[1] + dp[0]
              = 1 + 0
              = 1

        DP : 0 1 1 _ _ _ _

        -------------------------

        i = 3

        dp[3] = dp[2] + dp[1]
              = 1 + 1
              = 2

        DP : 0 1 1 2 _ _ _

        -------------------------

        i = 4

        dp[4] = dp[3] + dp[2]
              = 2 + 1
              = 3

        DP : 0 1 1 2 3 _ _

        -------------------------

        i = 5

        dp[5] = dp[4] + dp[3]
              = 3 + 2
              = 5

        DP : 0 1 1 2 3 5 _

        -------------------------

        i = 6

        dp[6] = dp[5] + dp[4]
              = 5 + 3
              = 8

        DP : 0 1 1 2 3 5 8

        Answer = dp[6]

        ============================================================
        WHY IS IT CALLED BOTTOM-UP?

        We already know:

        dp[0]
        dp[1]

        Using these,

        we compute

        dp[2]

        then

        dp[3]

        then

        dp[4]

        until

        dp[n]

        We move from the smallest subproblems
        towards the biggest problem.

        Hence,

        Bottom-Up Dynamic Programming.

        ============================================================
        TIME COMPLEXITY

        O(n)

        One loop from 2 to n.

        ============================================================
        SPACE COMPLEXITY

        O(n)

        DP array stores n+1 answers.

        ============================================================
        */

        // Base cases
        if (n == 0 || n == 1)
            return n;

        // dp[i] stores the ith Fibonacci number
        vector<int> dp(n + 1);

        // Initialize base cases
        dp[0] = 0;
        dp[1] = 1;

        // Fill the DP table from left to right
        for (int i = 2; i <= n; i++) {

            // Current Fibonacci number
            // = Previous Fibonacci + Second Previous Fibonacci
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // Final answer
        return dp[n];
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci Number = " << obj.fib(n);

    return 0;
}