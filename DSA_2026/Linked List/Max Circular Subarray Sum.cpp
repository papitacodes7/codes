// potd he ye did on 2/2/26 and iss din ke dusre question's nhi kiye..

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int n = arr.size();

        int totalSum = arr[0];
        int currMax = arr[0], maxSum = arr[0];
        int currMin = arr[0], minSum = arr[0];

        for (int i = 1; i < n; i++) {
            totalSum += arr[i];

            currMax = max(arr[i], currMax + arr[i]);
            maxSum = max(maxSum, currMax);

            currMin = min(arr[i], currMin + arr[i]);
            minSum = min(minSum, currMin);
        }

        // all elements negative
        if (maxSum < 0)
            return maxSum;

        int circularSum = totalSum - minSum;
        return max(maxSum, circularSum);
    }
};

// Example run
int main() {
    Solution s;
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    cout << s.maxCircularSum(arr);
    return 0;
}


// Circular array me maximum subarray ya to normal hoga (jo bina wrap kiye bana ho), jiska answer maxSum hota hai, ya phir circular hoga (jo end se start tak wrap kare). Circular subarray ka matlab hota hai ki poore array me se ek worst continuous part ko chhod diya jaye, isliye uska sum totalSum - minSum hota hai. Hume jo zyada bada sum mile, wahi answer chahiye, isliye end me max(maxSum, totalSum - minSum) return karte hain. Agar saare elements negative ho, to circular case possible nahi hota, isliye seedha maxSum return kar dete hain.


//currMax → abhi tak ka sum

// maxSum → overall max

// currMin → abhi tak ka worst sum

// minSum → overall worst

// totalSum - minSum(overall worst) → circular answer