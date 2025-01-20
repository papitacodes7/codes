#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size(), low = 0, high = n - 1;
        int ans = INT_MAX; // Sabse chhota element store karne ke liye variable

        while (low <= high) { 
            int mid = (low + high) / 2; // Array ka beech wala index nikalte hain

            // Agar left half sorted hai
            if (arr[low] <= arr[mid]) {
                ans = min(ans, arr[low]); // Left half ka sabse chhota element compare karte hain
                low = mid + 1; // Left half ko ignore karte hain aur right half check karte hain
            }
            else {
                // Agar right half sorted nahi hai
                ans = min(ans, arr[mid]); // Mid pe jo element hai usko minimum se compare karte hain
                high = mid - 1; // Right half ko ignore karte hain aur left half check karte hain
            }
        }
        return ans; // Sabse chhota element return karte hain
    }
};
