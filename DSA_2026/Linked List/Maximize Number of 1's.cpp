#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int l = 0;
        int zeroCount = 0;
        int maxLen = 0;

        for (int r = 0; r < arr.size(); r++) {
            if (arr[r] == 0) {
                zeroCount++;
            }

            // shrink window if zeroCount exceeds k
            while (zeroCount > k) {
                if (arr[l] == 0) {
                    zeroCount--;
                }
                l++;
            }

            // update answer
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 0, 0, 1, 0, 1, 0, 1};
    int k = 2;

    cout << sol.maxOnes(arr, k) << endl; // Output: 5

    return 0;
}

//Hum ek sliding window maintain karte hain

// Right pointer se window ko expand karte hain

// Window ke andar zeros count karte rehte hain

// Agar zeros > k ho jaaye:

// Left pointer ko aage badhate hain

// Jab tak zeros wapas ≤ k na ho jaaye

// Har valid window pe:

// max length = max(max length, current window size)