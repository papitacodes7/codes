#include <iostream>
#include <vector>
using namespace std;

// Ye function check karega ki kya given 'maxAllowedPages' limit ke andar books ko distribute karna possible hai ya nahi
bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages) {
    int st = 1;  // Kitne students ko books assign ki gayi hain
    int pages = 0;  // Current student ke pass total pages

    // Har book ko check karne ke liye loop
    for (int i = 0; i < n; i++) {
        // Agar koi ek book hi maxAllowedPages se zyada hai, toh yeh distribution possible nahi hai
        if (arr[i] > maxAllowedPages) {
            return false;
        }

        // Agar current student ke pass pages ka total 'maxAllowedPages' se kam hai, toh add kar do
        if (pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];  // Current student ko yeh book assign kar rahe hain
        } 
        else {
            // Agar pages limit cross ho gayi, toh naye student ko books deni padegi
            st++;  // Ek aur student assign kar diya
            pages = arr[i];  // Naye student ke pass ab yeh book hai
        }
    }

    // Agar students required se zyada ho gaye, toh return false
    return st > m ? false : true;
}

// Ye function minimum maximum pages dhoondhne ke liye binary search ka use karega
int findPages(vector<int>& arr, int n, int m) {
    // Agar students ki count books se zyada hai, toh allocation possible nahi hai
    if (m > n) return -1;

    int sum = 0;
    // Total pages ka sum calculate karenge taaki high boundary pata chale
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int ans = -1;
    int low = 0, high = sum;  // Binary search range set ki

    // Binary Search to find minimum of maximum pages allocation
    while (low <= high) {
        int mid = (low + high) / 2;  // Mid value nikali jo possible maxAllowedPages ho sakti hai

        // Check karo ki kya 'mid' pages ke andar books ko distribute karna possible hai
        if (isValid(arr, n, m, mid)) {
            ans = mid;  // Agar possible hai toh store kar lo
            high = mid - 1;  // Aur chhoti possible value ke liye search karo
        } 
        else {
            low = mid + 1;  // Agar nahi ho sakta, toh range badhao
        }
    }

    return ans;  // Final answer return karo jo minimum max pages allocation hai
}

int main() {
    vector<int> arr = {12, 34, 67, 90};  // Books ke pages
    int n = arr.size();
    int m = 2;  // Students count
    cout << "Minimum Maximum Pages: " << findPages(arr, n, m) << endl;
    return 0;
}
