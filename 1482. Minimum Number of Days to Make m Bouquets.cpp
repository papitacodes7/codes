#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Ye function check karta hai ki 'day' din tak 'm' bouquets banana possible hai ya nahi
    bool possible(vector<int>& arr, int day, int m, int k) {
        int n = arr.size(); // Array ka size nikal lo
        int cnt = 0;        // Continuous blooming flowers ka count rakho
        int noOfB = 0;      // Total bouquets ka count rakho

        // Poore array ko traverse karo
        for (int i = 0; i < n; i++) {
            if (arr[i] <= day) { 
                // Agar flower 'day' tak bloom ho jata hai, toh count badhao
                cnt++;
            } else {
                // Agar flower 'day' tak bloom nahi hota, toh current streak ko bouquets mein convert karo
                noOfB += (cnt / k); // Bouquet banane ke liye streak size ko 'k' se divide karo
                cnt = 0; // Streak reset kar do
            }
        }
        // Traverse khatam hone ke baad bhi leftover streak ko check karo
        noOfB += (cnt / k);

        // Agar bouquets 'm' ya usse zyada ban gaye, toh true return karo
        return noOfB >= m;
    }

    // Function jo minimum din find karega bouquets banane ke liye
    int minDays(vector<int>& arr, int m, int k) {
        long long val = m * 1ll * k * 1ll; // Total flowers ki zarurat calculate karo (long long overflow avoid karne ke liye)
        int n = arr.size(); // Array ka size store karo

        // Agar required flowers (m * k) array ke size se zyada ho, toh bouquets banana impossible hai
        if (val > n) return -1;

        int mini = INT_MAX, maxi = INT_MIN;
        // Array ka minimum aur maximum value find karo (day ke range ke liye)
        for (int i = 0; i < n; i++) {
            mini = min(mini, arr[i]); // Minimum bloom day nikal lo
            maxi = max(maxi, arr[i]); // Maximum bloom day nikal lo
        }

        // Binary search karte hain minimum aur maximum days ke beech
        int low = mini, high = maxi;
        while (low <= high) {
            int mid = (low + high) / 2; // Mid point calculate karo

            // Check karo ki 'mid' din tak bouquets banana possible hai ya nahi
            if (possible(arr, mid, m, k)) {
                // Agar possible hai, toh aur chhote din ke liye search karo
                high = mid - 1;
            } else {
                // Agar nahi possible, toh aur bade din ke liye search karo
                low = mid + 1;
            }
        }

        // Jab binary search khatam ho jaye, toh 'low' hi minimum din hoga bouquets banane ke liye
        return low;
    }
};
