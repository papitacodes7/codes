#include <bits/stdc++.h>
using namespace std;

// Yeh function check karega ki kya hum `dist` distance rakh ke `cows` ko place kar sakte hain ya nahi.
bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); // Stalls ka size nikal liya
    int cntCows = 1; // Pehli cow ko rakha
    int last = stalls[0]; // Pehli cow ka position track kar rahe hain
    
    for (int i = 1; i < n; i++) { 
        // Agar current stall aur last placed cow ke beech ka distance `dist` se zyada ya barabar hai
        if (stalls[i] - last >= dist) {
            cntCows++; // Ek aur cow place kar di
            last = stalls[i]; // Last placed cow ka position update kiya
        }
        if (cntCows >= cows) return true; // Agar saari cows place ho gayi toh return true
    }
    return false; // Agar cows place nahi ho paayi toh return false
}

// Yeh function maximum minimum distance find karega jisme cows ko place kiya ja sake
int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); // Stalls ka size
    sort(stalls.begin(), stalls.end()); // Stalls ko sort karna zaroori hai taaki proper placement ho sake

    int low = 1, high = stalls[n - 1] - stalls[0]; // Minimum aur maximum possible distance set kiya

    // Binary Search apply kar rahe hain best possible distance find karne ke liye
    while (low <= high) {
        int mid = (low + high) / 2; // Mid value nikal rahe hain jo ek possible distance ho sakta hai
        
        // Check kar rahe hain ki `mid` distance maintain karke cows place ho sakti hain ya nahi
        if (canWePlace(stalls, mid, k)) { 
            low = mid + 1; // Agar ho sakti hain toh distance badhane ki koshish karenge
        }
        else {
            high = mid - 1; // Agar nahi ho sakti toh distance kam kar denge
        }
    }
    return high; // Maximum possible minimum distance return karenge
}
