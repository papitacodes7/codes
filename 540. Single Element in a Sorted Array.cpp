#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        // Agar array mein sirf ek element hai
        if(n == 1) return arr[0];
        // Agar pehla element unique hai
        if(arr[0] != arr[1]) return arr[0];
        // Agar last element unique hai
        if(arr[n-1] != arr[n-2]) return arr[n-1];
        int low = 1, high = n-2;
        while(low <= high){
            int mid = (low + high) / 2;
            // Agar mid element unique hai
            if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) return arr[mid];
            // Mid element check karke range adjust karna
            if((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || mid % 2 == 0 && arr[mid] == arr[mid + 1]){
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1; // Ye line technically kabhi reach nahi honi chahiye
    }
};
