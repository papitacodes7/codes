#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function jo smallest divisor find karega jisse sum threshold se chhota ya equal ho
    int smallestDivisor(std::vector<int>& nums, int threshold) {
        int low = 1, high = 1000000; // Binary search ke liye range set karo
        // Binary search shuru karo to find the smallest valid divisor
        while (low <= high) {
            int mid = low + (high - low) / 2;  // Mid-point calculate karo (overflow avoid karne ke liye)
            // Check karo agar 'mid' ek valid divisor hai
            if (isValid(nums, mid, threshold)) {
                high = mid - 1;  // Agar valid hai, chhota divisor dhoondo
            } else {
                low = mid + 1;   // Agar valid nahi hai, bada divisor dhoondo
            }
        }
        return low;  // Return karo smallest divisor jo condition satisfy kare
    }

private:
    // Helper function jo check karega ki divisor valid hai ya nahi
    bool isValid(const std::vector<int>& nums, int divisor, int threshold) {
        int sum = 0; // Sum ko initialize karo
        // Array ke har element ke liye loop chalao
        for (int num : nums) {
            // Current number ko divisor se divide karo (round up karte hain)
            sum += (num + divisor - 1) / divisor; 
        }
        // Check karo agar total sum threshold se chhota ya equal hai
        return sum <= threshold;
    }
};
