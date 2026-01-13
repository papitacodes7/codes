#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int result = floor(sqrt(n - 1));
    cout << result;

    return 0;
}


//Question me clearly likha hai perfect squares less than n, to hum isko seedha math me likh sakte hain: agar koi number perfect square hai, to wo k² ke form me hoga. Ab condition hai k² < n. Dono side square root le lo, to k < √n aa jaata hai. Ab hume bas ye dekhna hai ki √n se chhote kitne whole numbers possible hain, kyunki k sirf integer ho sakta hai. Whole numbers count karne ke liye floor use hota hai. Aur kyunki square strictly less than n chahiye (equal nahi), isliye safely √(n−1) lete hain. Isse directly answer mil jaata hai.