#include <bits/stdc++.h>
using namespace std;

int main() {
    // -------- Example Input --------
    int n = 5;
    int arr[] = {4, 1, 3, 2, 5};

    int q = 3;
    int queries[] = {3, 4, 6};
    // --------------------------------

    cout << "Original array: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    sort(arr, arr + n);

    cout << "Sorted array:   ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int pre[n + 1];
    pre[0] = 0;

    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + arr[i - 1];
    }

    cout << "Prefix sum:     ";
    for(int i = 0; i <= n; i++) cout << pre[i] << " ";
    cout << endl << endl;

    // -------- Query Processing --------
    for(int i = 0; i < q; i++){
        int x = queries[i];

        int idx = upper_bound(arr, arr + n, x) - arr;

        cout << "Query x = " << x << " -> ";
        cout << "count = " << idx << ", sum = " << pre[idx] << endl;
    }

    return 0;
}


//Pehle hum array ko sort kar dete hain, phir ek prefix array banate hain jisme hum sum store karte jaate hain using pre[i] = pre[i-1] + arr[i-1], matlab pehle i elements ka total sum. Ab jab koi query value x aati hai, hum upper_bound lagate hain jo x se strictly bade element ka address return karta hai. Kyunki upper_bound address deta hai, hume us address ko arr se minus karna padta hai, kyunki arr ka matlab hota hai &arr[0], aur address minus address karne se hume ye pata chalta hai ki beech me kitne elements aaye — wahi count hota hai idx. idx ka matlab hai jitne elements x se chhote ya barabar hain, aur un sab ka sum hume direct pre[idx] se mil jaata hai. Is approach se hum bina poora array traverse kiye har query ka answer efficiently nikaal lete hain.

// Time Complexity: Array sort karne me O(n log n), prefix sum banane me O(n), aur har query ke liye upper_bound lagane me O(log n) lagta hai, toh total complexity O(n log n + q log n) hoti hai.
// Space Complexity: Prefix sum array ke liye extra O(n) space lagti hai.




//https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/?utm_source=header&utm_medium=search&utm_campaign=he-search

// skipped 20 and 21