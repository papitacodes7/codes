#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
    int n = arr.size();
    // Agar array mein sirf ek element hai
    if(n == 1) return 0;
    // Agar pehla element peak hai
    if(arr[0] > arr[1]) return 0;
    // Agar last element peak hai
    if(arr[n-1] > arr[n-2]) return n-1;

    int low = 1, high = n-2;
    while(low <= high){
        int mid = (low + high) / 2;
        // Agar mid element peak hai
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
            return mid;
        }
        // Agar mid element right slope pe hai
        else if(arr[mid] > arr[mid - 1]){
            low = mid + 1;
        }
        // Agar mid element left slope pe hai
        else {
            high = mid - 1;
        }
    }
    return -1; // Ye line technically kabhi reach nahi honi chahiye
    }
};