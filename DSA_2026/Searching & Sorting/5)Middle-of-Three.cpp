#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int middle(int a, int b, int c) {
        if ((a < c && a > b) || (a > c && a < b))
            return a;
        else if ((b > a && b < c) || (b > c && b < a))
            return b;
        else
            return c;
    }
};

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    Solution obj;
    cout << obj.middle(a, b, c) << endl;

    return 0;
}


// Basically intuition ye hai ki **teen distinct numbers me se ek number hamesha beech me hota hi hai**. Ab maan lo hum `a` ko check kar rahe hain. Agar `a > b` aur `a < c` hai, iska matlab `b < a < c` — lekin ye sirf **ek assumption** hai jisme humne maan liya ki `b < a`. Reality me order ulta bhi ho sakta hai, yani `c < a < b`, isliye hume `a > c` aur `a < b` wala case bhi consider karna padta hai. Same logic hum `b` ke liye lagate hain, kyunki `b` bhi middle ho sakta hai. Aur agar na `a` middle nikle, na `b`, to phir obviously teesra number `c` hi middle hoga, isliye `else` me hum third element return kar dete hain.


// 6th wala skipped...