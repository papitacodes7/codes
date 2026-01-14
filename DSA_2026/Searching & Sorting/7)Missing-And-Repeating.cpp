#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {

        long long n = arr.size();

        // Expected sums
        long long expSum = n * (n + 1) / 2;
        long long expSqSum = n * (n + 1) * (2 * n + 1) / 6;

        // Actual sums
        long long actualSum = 0, actualSqSum = 0;
        for (int x : arr) {
            actualSum += x;
            actualSqSum += 1LL * x * x;
        }

        // Differences
        long long diff = expSum - actualSum;       // M - R
        long long sqDiff = expSqSum - actualSqSum; // M^2 - R^2

        // M + R
        long long sumMR = sqDiff / diff;

        // Solve
        long long missing = (diff + sumMR) / 2;
        long long repeating = sumMR - missing;

        return { (int)repeating, (int)missing };
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    vector<int> result = obj.findTwoElement(arr);

    // Output: Repeating and Missing
    cout << result[0] << " " << result[1] << endl;

    return 0;
}


//Is problem me given hota hai ki 1 se n tak ke numbers hone chahiye, lekin ek number missing hota hai (M) aur ek number repeat ho raha hota hai (R). Pehle hum expected sum nikalte hain jo ideally hona chahiye, yani n(n+1)/2, aur expected square sum jo hota hai n(n+1)(2n+1)/6. Phir array se actual sum aur actual square sum calculate karte hain. Ab kyunki ek number missing hai, actual sum me woh value add nahi hui, aur jo number repeat hua hai woh ek extra baar add ho gaya, isliye expectedSum - actualSum = M - R milta hai. Same logic square sums pe apply karte hain jisse expectedSqSum - actualSqSum = M² - R² milta hai. Ab identity use karte hain: M² - R² = (M - R)(M + R), to jab hum sqDiff / diff karte hain to directly M + R mil jata hai. Ab jab M - R aur M + R dono mil gaye, to unhe add karke missing number M nikal jata hai, aur phir M + R me se M subtract karke repeating number R mil jata hai. End me answer return kar dete hain as [repeating, missing].

// Time Complexity: O(n)
// Space Complexity: O(1)

// refer to 5 if you don't see 6th one..