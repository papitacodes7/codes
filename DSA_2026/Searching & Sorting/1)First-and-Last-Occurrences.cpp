#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        int n = arr.size();
        int first = -1, last = -1;
        
        // Find first occurrence
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                first = mid;
                high = mid - 1;   // move left
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        // Find last occurrence
        low = 0;
        high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                last = mid;
                low = mid + 1;    // move right
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return {first, last};
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int x = 5;

    Solution obj;
    vector<int> result = obj.find(arr, x);

    cout << "First Occurrence: " << result[0] << endl;
    cout << "Last Occurrence: " << result[1] << endl;

    return 0;
}




// Basically, binary search laga dete hain kyunki kaam sirf search ka hi hai aur array already sorted hai. Normal binary search me jaise hi element milta hai hum return kar dete hain, but yaha thoda twist hai. Hume sirf element milna nahi chahiye, balki uska first aur last occurrence chahiye. Isliye jab binary search ke beech me x milta hai, tab hum rukte nahi. First occurrence ke liye hum sochte hain ki ho sakta hai ye x aur left side me bhi present ho, isliye answer ko store karke left side (high = mid − 1) me traverse karte hain. Jaise example me arr = [1,3,5,5,5,5,67] aur x = 5, mid pe 5 milta hai, but first 5 index 2 pe hai, to hum left me search continue karte hain. Similarly, last occurrence ke liye jab x milta hai, hum sochte hain ki right side me bhi x ho sakta hai, isliye answer update karke right side (low = mid + 1) me traverse karte hain. Is tarah binary search ko thoda modify karke hum dono boundaries nikaal lete hain efficiently.

// Time Complexity:
// O(log n) — do baar binary search lagta hai.(Jab tak hum array ko line-by-line scan nahi kar rahe aur har step me search space ko half kar rahe hain, tab tak time complexity O(log n) hi rehti hai.)

// Space Complexity:
// O(1) — sirf constant extra variables use hote hain.