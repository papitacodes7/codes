#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Count trailing zeroes in x!
    long long countZeros(long long x) {
        long long cnt = 0;
        while (x > 0) {
            x /= 5;
            cnt += x;
        }
        return cnt;
    }

    // Find smallest x such that x! has at least n trailing zeroes
    int findNum(int n) {
        long long low = 0, high = 5LL * n;
        long long ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countZeros(mid) >= n) {
                ans = mid;        // possible answer
                high = mid - 1;   // try smaller x
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;
    cout << obj.findNum(n) << endl;

    return 0;
}


// Trailing zeroes in a factorial are created by the multiplication of 2 and 5, because a trailing zero means the number is divisible by 10. In any factorial, factors of 2 are always present in excess since every even number contributes a 2, whereas factors of 5 appear much less frequently. Therefore, the number of trailing zeroes in x! is completely determined by how many times 5 divides into the numbers from 1 to x. As x increases, the count of factor 5 (and hence trailing zeroes) never decreases, which makes this count a monotonic function. Using this property, we apply binary search to efficiently find the smallest value of x for which the number of trailing zeroes in x! is at least n.

//30 wala is 25th wala jo kr rkha tha toh skipping it.. on 21/1/26..

// skipped 31,32,33 on 22//1/26
