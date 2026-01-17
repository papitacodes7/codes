#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 0);

        long long left = 1;
        for (int i = 0; i < n; i++) {
            res[i] = left;
            left *= arr[i];
        }

        long long right = 1;
        for (int j = n - 1; j >= 0; j--) {
            res[j] *= right;
            right *= arr[j];
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 2, 3, 4};
    vector<int> result = sol.productExceptSelf(arr);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}


//basically isme like jo bhi arr[i] hoga uske left me jo els honga and uske jo right me jo els honge unko product krke return krna he.. to do all that firstly ek vector create kro n,1 fir left wala for loop chalana he zero se n-1 tk and hume jo vector banaya he uski pos ko update krte jaana he left se and left ko multiply bhi krte jaana he.. ese krte rahenge toh vector me left me jitna bhi product bana he na for a particular arr[i]] woh store hota chla jyga.. note ki jese hi apan ne left wala for loop finish kiya he.. vector me left product yaani ki prefix stored ho chuka he and now we have to do same stuff just from the right side.. usse suffix hi kehlo.. now right wala loop chlega n-1 se <=0 tk..now hume krna he ans[i] *= right because jo ans wala vector he na usme hum already prefix for all arr[i] daal chuke hein... now right ko bhi update krna he as right*= arr[i]] that's it.. in the end return ans.


//Basically har `arr[i]` ke liye hume uske **left side ke saare elements ka product** aur **right side ke saare elements ka product** chahiye, bina `arr[i]` ko include kiye. Iske liye hum ek result vector banate hain aur pehle left-to-right loop chalaate hain jisme `left = 1` rakhkar har index `i` pe `ans[i] = left` assign kar dete hain, phir `left *= arr[i]`, taaki `ans[i]` me sirf prefix (left product) store ho. Is loop ke baad har position pe left product aa chuka hota hai. Phir right-to-left loop chalate hain with `right = 1`, jisme `ans[i] *= right` karte hain kyunki `ans[i]` me pehle se left product pada hai aur ab hume uske saath right product multiply karke value complete karni hoti hai, phir `right *= arr[i]` update karte hain. Is tarah final `ans[i]` = left product × right product ban jata hai, bina division use kiye aur zeros automatically handle ho jaate hain. **Time Complexity `O(n)`** hai kyunki do linear loops hain, aur **Extra Space Complexity `O(1)`** hai (output array ko exclude karke).


