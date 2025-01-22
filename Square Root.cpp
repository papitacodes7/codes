#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int floorSqrt(int n) {
        // Special case for 0 aur 1
        if(n == 0 || n == 1){
            return n;
        }

        int low = 0, high = n, ans; // Low, high, aur answer variables initialize karo

        // Binary search karte hain floor of square root nikalne ke liye
        while(low <= high){
            int mid = (low + high) / 2; // Mid value calculate karo

            // Check karo agar mid perfect square root hai
            if((mid * mid) == n){
                return mid;
            }

            // Agar mid*mid n se kam hai, toh lower half discard karo
            if((mid * mid) < n){
                low = mid + 1;
                ans = mid; // Answer ko mid pe update karo
            } else {
                // Agar mid*mid n se zyada hai, toh upper half discard karo
                high = mid - 1;
            }
        }

        // Floor value of sqrt(n) return karo
        return ans;
    }
};
