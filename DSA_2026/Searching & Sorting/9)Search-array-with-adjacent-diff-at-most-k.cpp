#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
        int i = 0;
        int n = arr.size();

        while (i < n) {
            if (arr[i] == x)
                return i;

            int diff = abs(arr[i] - x);
            i += max(1, diff / k);
        }
        return -1;
    }
};

int main() {
    vector<int> arr = {4, 5, 6, 7, 6};
    int k = 1;
    int x = 6;

    Solution obj;
    int result = obj.findStepKeyIndex(arr, k, x);

    cout << result << endl;

    return 0;
}


// Question me diya hua hai ki kisi bhi arr[i] par adjacent elements ka difference maximum k tak hi + ya - ho sakta hai.
// Iska matlab ye hua ki agar hum kisi index i par khade hain aur hume element x dhoondhna hai, toh pehle hum current value aur x ka difference nikal sakte hain using
// diff = abs(arr[i] - x).

// Ab kyunki ek step me value maximum k se hi change ho sakti hai, toh logically x tak pahunchne ke liye minimum diff / k steps toh lagenge hi.
// Isliye har index ko one-by-one check karne ke bajay, hum direct diff / k indices aage jump kar sakte hain.
// Agar kabhi diff / k zero aa jaaye (jab diff < k ho), toh infinite loop avoid karne ke liye hum at least 1 step aage badhte hain.

// Is tarah hum unnecessary indices ko skip kar dete hain aur search ko fast bana dete hain.

// Time Complexity
// Best case: O(1) (agar element pehle hi mil jaaye)

// Worst case: O(n)

// Average case: Linear se better, kyunki multiple indices skip ho jaate hain

// Space Complexity
// O(1) (koi extra space use nahi ho rahi)