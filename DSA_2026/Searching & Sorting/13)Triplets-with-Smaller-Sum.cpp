#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        sort(arr, arr + n);
        long long count = 0;

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                long long curr = arr[i] + arr[j] + arr[k];

                if (curr < sum) {
                    count += (k - j);  // count all valid middle elements
                    j++;
                } else {
                    k--;
                }
            }
        }
        return count;
    }
};

int main() {
    int n;
    long long sum;
    cin >> n >> sum;

    long long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.countTriplets(n, sum, arr) << endl;

    return 0;
}


//Is approach mein hum pehle array ko sort karte hain aur phir har fixed index i ke liye two pointers j aur k use karte hain. Jab arr[i] + arr[j] + arr[k] < sum hota hai, tab sirf count++ karna galat hota, kyunki j+1 aur k ke beech jo elements hain (j+1 … k) unke saath bhi valid triplets banti hain. Sorted array ki wajah se, agar arr[i] + arr[j] + arr[k] valid hai, toh arr[i] + arr[j] + arr[j+1], arr[i] + arr[j] + arr[j+2] … arr[i] + arr[j] + arr[k] sab bhi valid honge. Isliye hum count += (k - j) karte hain, taaki beech ka koi bhi valid combination ignore na ho. Agar hum sirf count++ karte, toh (j+1 … k) ke beech wale saare valid triplets exclude ho jaate. Agar sum bada ho jaata hai, toh k-- karke sum ko kam karte hain.

// Time Complexity:
// Array sort karne mein O(n log n) lagta hai. Uske baad outer loop O(n) aur inner two-pointer loop O(n) mein complete ho jaata hai, isliye overall time complexity O(n²) hai.

// Space Complexity:
// Algorithm constant extra space use karta hai (sorting in-place hoti hai), isliye space complexity O(1) hai.