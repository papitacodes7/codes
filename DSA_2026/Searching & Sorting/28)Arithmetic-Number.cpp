#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int inSequence(int a, int b, int c) {
        // If common difference is 0, sequence is: a, a, a, ...
        // So b exists only if b == a
        if (c == 0) return a == b;

        // b must be reachable from a using steps of size c
        // (b - a) % c == 0  → exact number of steps
        // (b - a) / c >= 0  → no backward movement
        return ((b - a) % c == 0 && (b - a) / c >= 0);
    }
};

int main() {
    Solution obj;

    // Sample test cases
    cout << obj.inSequence(1, 3, 2) << endl; // 1 (true)
    cout << obj.inSequence(1, 2, 3) << endl; // 0 (false)
    cout << obj.inSequence(1, 2, 4) << endl; // 0 (false)
    cout << obj.inSequence(5, 5, 0) << endl; // 1 (true)
    cout << obj.inSequence(5, 6, 0) << endl; // 0 (false)

    return 0;
}


