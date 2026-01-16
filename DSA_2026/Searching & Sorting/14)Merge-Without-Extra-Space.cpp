#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int i = a.size() - 1;
        int j = 0;

        // Swap elements if they are in wrong arrays
        while (i >= 0 && j < b.size()) {
            if (a[i] < b[j]) {
                break;
            } else {
                swap(a[i], b[j]);
                i--;
                j++;
            }
        }

        // Sort both arrays to restore order
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    Solution obj;
    obj.mergeArrays(a, b);

    // Print merged arrays
    for (int x : a) cout << x << " ";
    cout << endl;

    for (int x : b) cout << x << " ";
    cout << endl;

    return 0;
}


// Is approach mein hum a array ke last element aur b array ke first element ko compare karte hain. Agar a ka last element b ke first element se chhota ho, toh matlab dono arrays already correct order mein hain, bas a aur b ko sort karke return kar dete hain. Agar a ka last element b ke first element se bada ho, toh un dono ko swap kar dete hain, phir a ka last pointer ek step peeche (i--) aur b ka first pointer ek step aage (j++) move kar dete hain. Ye process tab tak chalta hai jab tak i >= 0 aur j < b.size() ho. End mein, kyunki swaps ke baad arrays internally unsorted ho sakti hain, hum dono arrays ko sort kar dete hain taaki final result sorted mile.

// Time Complexity:
// While loop maximum O(min(n, m)) times chalta hai. Uske baad sorting a ke liye O(n log n) aur b ke liye O(m log m) lagta hai. Isliye overall time complexity O(n log n + m log m) hai.

// Space Complexity:
// Koi extra array use nahi hota, sirf constant variables use hote hain. Sorting in-place hoti hai, isliye space complexity O(1) hai.