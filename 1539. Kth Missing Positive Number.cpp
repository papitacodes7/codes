#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, n = arr.size(), high = n - 1;

        // Binary Search use karke find karenge ki `k`-th missing number kahaan hoga
        while (low <= high) {
            int mid = (low + high) / 2;

            // Yeh check kar raha hai ki arr[mid] tak kitne numbers missing hain
            int missing = arr[mid] - (mid + 1);

            if (missing < k) { 
                // Agar ab tak missing numbers `k` se kam hain, toh right side search karo
                low = mid + 1;
            } 
            else {
                // Agar missing numbers `k` ya usse zyada ho gaye, toh left side search karo
                high = mid - 1;
            }
        }

        // Binary search ke baad `low` uss index pe aayega jahan tak ke numbers present hain.
        // Ab `low` ke pehle ke saare numbers array me hain, toh missing `k`-th number `low + k` hoga
        
        return low + k;
    }
};
