#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    int solve(int n, int k) {
        if (n == 1) return 0;
        return (solve(n - 1, k) + k) % n;
    }
    
    int josephus(int n, int k) {
        return solve(n, k) + 1; // convert to 1-based index
    }
};

int main() {
    Solution obj;
    int n, k;
    cin >> n >> k;
    cout << obj.josephus(n, k) << endl;
    return 0;
}


// potd he of 24/1/26

//https://youtu.be/7PdYI_Mzf8g?si=wSTQO9oKz1Du7UYN

//The Josephus problem is solved using recursion by observing that when one person is eliminated from a circle of n people, the problem reduces to a smaller circle of n−1 people, but the survivor’s position shifts by k due to circular rotation. Using 0-based indexing simplifies this shift, giving the recurrence relation J(n) = (J(n−1) + k) % n with base case J(1) = 0, since the only person survives. The final answer is converted back to 1-based indexing by adding 1. The time complexity of this solution is O(n) because the recursive function is called once for each value from n to 1, and the space complexity is O(n) due to the recursion stack.