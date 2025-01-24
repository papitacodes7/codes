#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // yeh function array mein se maximum value dhoondta hai
    int findMax(vector<int>& v) {
        int n = v.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    // yeh function har pile ko 'mid' bananas per kitne hours lagenge, yeh calculate karta hai
    long long calcThrs(vector<int>& v, int mid) {
        long long totalH = 0; // total hours ko 0 se initialize karta hai
        int n = v.size(); // 'v' array ka size n mein store kar raha hai
        for (int i = 0; i < n; i++) {
            // har pile ko 'mid' bananas per hours ko calculate karta hai aur totalH mein add karta hai
            totalH += (v[i] + mid - 1) / mid; // yahan hum ceil ke jagah (v[i] + mid - 1) / mid use kar rahe hain
        }
        return totalH; // total hours return karta hai
    }

    // yeh function binary search use karke minimum eating speed find karta hai
    int minEatingSpeed(vector<int>& v, int h) {
        int low = 1, high = findMax(v); // low ko 1 se aur high ko array ke maximum value se initialize karta hai
        while (low <= high) {
            int mid = (low + high) / 2; // mid point calculate karta hai
            long long totalH = calcThrs(v, mid); // mid bananas per total hours calculate karta hai
            if (totalH <= h) {
                // agar total hours h se kam ya barabar hain, toh mid ko reduce karke binary search ko narrow karta hai
                high = mid - 1;
            } else {
                // agar total hours h se zyada hain, toh minimum speed ko badhata hai
                low = mid + 1;
            }
        }
        return low; // minimum eating speed return karta hai
    }
};
